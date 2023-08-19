#include<iostream>
using namespace std;
const int N = 100;
int A[N];//�����ģ
int m[N][N];//���Ž�
int s[N][N];
void MatrixChain(int n)
{
	int r, i, j, k;
	for (i = 0; i <= n; i++)//��ʼ���Խ���
	{
		m[i][i] = 0;
	}
	for (r = 2; r <= n; r++)//r����������
	{
		for (i = 1; i <= n - r + 1; i++)//r�������r-1����϶�����β������ŵ�
		{
			j = i + r - 1;
			m[i][j] = m[i][i]+m[i + 1][j] + A[i - 1] * A[i] * A[j];
			s[i][j] = i;
			for (k = i + 1; k < j; k++)//�任�ָ�λ�ã���һ����
			{
				int t = m[i][k] + m[k + 1][j] + A[i - 1] * A[k] * A[j];
				if (t < m[i][j])//����任���λ�ø��ţ����滻ԭ���ķָ�������
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}
void print(int i, int j)
{
	if (i == j)
	{
		cout << "A[" << i << "]";
		return;
	}
	cout << "(";
	print(i, s[i][j]);
	print(s[i][j] + 1, j);//�ݹ�1��s[1][j]
	cout << ")";
}
int main()
{
	int n;//n������
	cin >> n;
	int i, j;
	for (i = 0; i <= n; i++)
	{
		cin >> A[i];
	}
	MatrixChain(n);
	cout << "���������ŵķ�ʽΪ��";
	print(1, n);
	cout << "\n��С��������ֵΪ��" << m[1][n] << endl;
	return 0;
}



