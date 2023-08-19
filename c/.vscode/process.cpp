#include "iostream"
#include "queue"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

typedef struct PCB
{
    string name;            //进程名
    int arrive;             //到达时间
    int need;               //服务时间
    int priority;           //优先级(wait,run,finish)
    int used;               //已占用CPU时间
    string status;          //进程状态
    int finish;             //完成时间
    int start;              //开始运行时间
    float trunaround;       //周转时间
    float weightTurnaround; //带权周转时间
    bool operator<(const PCB &a) const//重载<操作符。可以对两个node使用<操作符进行比较
    {
        return arrive > a.arrive;
    }//结构体内嵌比较函数,比较进程到达时间(从大到小排)
} pcb;

struct cmp_need
{
    bool operator()(PCB a, PCB b)
    {
        return a.need > b.need;
    }//比较进程服务时间
};

struct cmp_priority
{
    bool operator()(pcb a, pcb b)
    {
        if (a.priority == b.priority)
            return a.arrive > b.arrive;
        return a.priority < b.priority;
    }//比较进程优先级
};

priority_queue<pcb> p;
priority_queue<pcb, vector<pcb>, cmp_need> q;

int finish_prior;

void init()//初始化pcb
{
    pcb tmp[5] = {
        {"p1", 0, 3, 2, 0, "Wait", 0, 0, 0, 0},
        {"p2", 2, 6, 3, 0, "Wait", 0, 0, 0, 0},
        {"p3", 4, 4, 1, 0, "Wait", 0, 0, 0, 0},
        {"p4", 6, 5, 5, 0, "Wait", 0, 0, 0, 0},
        {"p5", 8, 2, 4, 0, "Wait", 0, 0, 0, 0}};
    p.push(tmp[0]);
    p.push(tmp[1]);
    p.push(tmp[2]);
    p.push(tmp[3]);
    p.push(tmp[4]);
}

void output(queue<pcb> &p)
{
    pcb q;
    cout << "进程名\t到达时间 服务时间 开始时间 已占用CPU时间 进程状态" << endl;
    while (p.size() != 0)
    {
        q = p.front();
        if (q.arrive <= finish_prior)
        {
            cout << q.name << "\t" << q.arrive << "\t " << q.need << "\t  ";
            cout << q.start << "\t   " << q.used << "\t\t " << q.status << endl;
        }
        p.pop();
    }
    cout << endl << endl;
}

void output_finish(queue<pcb> &q)
{
    pcb t;
    float avg_trun, avg_wei_trun;
    avg_trun = avg_wei_trun = 0;
    int size = q.size();
    cout << "所有进程执行结束之后的相关情况" << endl
         << endl;
    cout << "进程名\t到达时间 服务时间 开始时间 完成时间 周转时间 带权周转时间" << endl;
    while (q.size() != 0)
    {
        t = q.front();
        cout << t.name << "\t" << t.arrive << "\t " << t.need << "\t  ";
        cout << t.start << "\t   " << t.finish << "\t \t" << t.trunaround << "\t" << t.weightTurnaround << endl;
        avg_trun += t.trunaround;
        avg_wei_trun += t.weightTurnaround;
        q.pop();
    }
    cout << "平均周转时间：" << avg_trun / size << endl;
    cout << "平均带权周转时间：" << avg_wei_trun / size << endl;
    cout << endl << endl;
}

void FCFS()
{
    queue<pcb> temp, q;
    priority_queue<pcb> tran; //用于copy p中的元素
    finish_prior = 0;
    pcb t;
    int n = p.size();
    for (int i = 0; i < n; i++)
    {
        t = p.top();
        if (i == 0)
        {
            t.start = t.arrive;
        }
        else
        {
            t.start = finish_prior > t.arrive ? finish_prior : t.arrive;
        }
        t.finish = t.start + t.need;
        t.trunaround = t.finish - t.arrive;
        t.weightTurnaround = t.trunaround / t.need;
        t.status = "Run";
        finish_prior = t.finish;
        while (t.used < t.need)
        {
            t.used++;
            cout << "正在运行的进程" << endl;
            cout << "进程名\t到达时间 服务时间 开始时间 已占用CPU时间 进程状态" << endl;
            cout << t.name << "\t" << t.arrive << "\t " << t.need << "\t  ";
            cout << t.start << "\t   " << t.used << "\t\t " << t.status << endl;
        }
        t.status = "Finish";
        q.push(t);
        p.pop();
        cout << "进程" << t.name << "执行结束之后就绪队列中的进程" << endl;
        tran = p;
        while (!tran.empty())
        {
            temp.push(tran.top());
            tran.pop();
        }
        output(temp);
    }
    output_finish(q);
}

void PSA()
{
    finish_prior = 0;
    //int current = 0;
    bool flag = true;                                    //是否为第一个进程
    priority_queue<pcb, vector<pcb>, cmp_priority> q;    //就绪队列
    priority_queue<pcb, vector<pcb>, cmp_priority> tran; //copy q 中的元素
    priority_queue<pcb> f;                               //已完成的进程
    queue<pcb> temp;                                     //拷贝要输出的优先级队列
    pcb t;
    while (!p.empty() || !q.empty())
    {
        cout << "第" << finish_prior + 1 << "个时间片" << endl;
        t = p.top();
        //此时没有可运行的进程，时间加加
        while (t.arrive > finish_prior && q.empty())
        {
            finish_prior++;
        }
        while (!p.empty() && t.arrive <= finish_prior)
        { //将此时已就绪的队列放入就绪队列
            q.push(t);
            p.pop();
            t = p.top();
        }
        t = q.top();
        if (t.used == 0)
        {
            t.start = t.arrive < finish_prior ? finish_prior : t.arrive;
        }

        if (t.used < t.need)
        {
            t.status = "Run";
            t.used++;
            cout << "正在运行的进程" << endl;
            cout << "进程名\t到达时间 服务时间 开始时间 已占用CPU时间 进程状态" << endl;
            cout << t.name << "\t" << t.arrive << "\t " << t.need << "\t  ";
            cout << t.start << "\t   " << t.used << "\t\t " << t.status << endl;
            t.status = "Wait";
            t.priority--;

            //current++;
            finish_prior++;

            if (t.used == t.need)
            {
                t.finish = finish_prior;
                //cout<< "完成时间：" << t.finish<<endl;
                t.trunaround = t.finish - t.arrive;
                t.weightTurnaround = t.trunaround / t.need;
                t.status = "Finish";
                //finish_prior = t.finish;
                q.pop();
                f.push(t);
            }
            else
            {
                q.pop();
                q.push(t);
            }
        }
        cout << "进程" << t.name << "执行一个时间片之后就绪队列中的进程" << endl;
        if (!p.empty())
            t = p.top();
        //将运行完这个时间片后p中已就绪的进程添加到就绪队列
        while (!p.empty() && t.arrive <= finish_prior)
        {
            q.push(t);
            p.pop();
            t = p.top();
        }
        tran = q;
        while (!tran.empty())
        {
            temp.push(tran.top());
            tran.pop();
        }
        output(temp); //打印就绪队列
    }
    while (!f.empty())
    {
        temp.push(f.top());
        f.pop();
    }
    output_finish(temp); //打印运行完成后的队列情况
}

void SJF()
{
    pcb t;
    queue<pcb> temp;
    priority_queue<pcb, vector<pcb>, cmp_need> tran; //copy q 中的元素
    finish_prior = 0;
    bool flag = true;      //是否为第一个运行的进程
    priority_queue<pcb> f; //运行完成后的进程队列
    while (true)
    { //所有进程执行完退出
        if (p.empty() && q.empty())
        {
            break;
        }
        t = p.top();
        while (t.arrive > finish_prior && q.empty())
        {
            finish_prior++;
        }
        while (!p.empty() && t.arrive <= finish_prior)
        {
            q.push(t);
            p.pop();
            t = p.top();
        }
        t = q.top();
        if (t.arrive <= finish_prior)
        {
            if (flag)
            { //是否是第一个进程
                t.start = t.arrive;
                flag = false;
            }
            else
            {
                t.start = finish_prior > t.arrive ? finish_prior : t.arrive;
            }
            t.finish = t.start + t.need;
            t.trunaround = t.finish - t.arrive;
            t.weightTurnaround = t.trunaround / t.need;
            t.status = "Run";
            finish_prior = t.finish;
            while (t.used < t.need)
            {
                t.used++;
                cout << "正在运行的进程" << endl;
                cout << "进程名\t到达时间 服务时间 开始时间 已占用CPU时间 进程状态" << endl;
                cout << t.name << "\t" << t.arrive << "\t " << t.need << "\t  ";
                cout << t.start << "\t   " << t.used << "\t\t " << t.status << endl;
            }

            t.status = "Finish";
            f.push(t);
            q.pop();
            cout << "进程" << t.name << "执行结束之后就绪队列中的进程" << endl;
            if (!p.empty())
                t = p.top();
            while (!p.empty() && t.arrive <= finish_prior)
            {
                q.push(t);
                p.pop();
                t = p.top();
            }
            tran = q;
            while (!tran.empty())
            {
                temp.push(tran.top());
                tran.pop();
            }
            output(temp);
        }
    }
    while (!f.empty())
    {
        temp.push(f.top());
        f.pop();
    }
    output_finish(temp);
}

priority_queue<pcb> f; //已完成的进程
int cnt; //执行了几个时间片
//运行队列q size个时间片,并将该进程放入下一队列,flag判断是否是最后一个队列
void run(queue<pcb> &q, queue<pcb> &p, int size, bool flag)
{
    cnt = 0;
    pcb t = q.front();
    if (t.used == 0)
    {
        t.start = finish_prior;
    }
    while (true)
    {
        size--;
        cnt++;
        t.used++;
        finish_prior++;
        t.status = "Run";
        cout << "正在运行的进程" << endl;
        cout << "进程名\t到达时间 服务时间 开始时间 已占用CPU时间 进程状态" << endl;
        cout << t.name << "\t" << t.arrive << "\t " << t.need << "\t  ";
        cout << t.start << "\t   " << t.used << "\t\t " << t.status << endl;
        if (t.used == t.need)
        {
            t.finish = finish_prior;
            t.trunaround = t.finish - t.arrive;
            t.weightTurnaround = t.trunaround / t.need;
            t.status = "Finish";
            q.pop();
            f.push(t);
            break;
        }
        if (!size)
        {
            t.status = "Wait";
            q.pop();
            if (flag)
            {
                q.push(t);
            }
            else
            {
                p.push(t);
            }
            break;
        }
    }
}


int main()
{
    int menu;
    init();
    priority_queue<pcb> tmp = p;
    do
    {
        cout << "==================\n菜单\n1.优先级调度算法\n2.先来先服务算法\n3.短作业优先算法\n输入0结束程序\n==================" << endl;
        cin >> menu;
        switch (menu)
        {
        case 0:
            break;
        case 1:
            PSA();
            break;
        case 2:
            FCFS();
            break;
        case 3:
            SJF();
            break;
        default:
            cout << "输入错误，请重新选择操作！！！" << endl;
            break;
        }
        p = tmp;
    } while (menu != 0);
    return 0;
}
