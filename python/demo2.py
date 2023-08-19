import math
import turtle

turtle.setup(1920,1080,0,0)
turtle.pencolor("black")
turtle.speed(5)


turtle.fillcolor("black") #绘制图形的填充颜色
turtle.pendown()

turtle.circle(200,180) #画圆，半径为正(负)，表示圆心在画笔的左边(右边)画圆
turtle.circle(100,180)
turtle.circle(-100,180)
turtle.end_fill() #填充完成
turtle.circle(-200,180)
turtle.penup() #提起画笔


turtle.goto(15,80) #将画笔移动到坐标为x,y的位置
turtle.pencolor("black")
turtle.pendown()
turtle.fillcolor("black") #绘制图形的填充颜色
turtle.begin_fill() #准备开始填充图形
turtle.circle(30,360)
turtle.end_fill() #填充完成
turtle.penup() #提起画笔

turtle.goto(15,300) #将画笔移动到坐标为x,y的位置
turtle.pencolor("black")
turtle.pendown()
turtle.fillcolor("white") #绘制图形的填充颜色
turtle.begin_fill() #准备开始填充图形
turtle.circle(30,360)
turtle.end_fill() #填充完成

turtle.done() #使turtle窗口不会自动消失