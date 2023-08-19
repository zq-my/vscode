import turtle

turtle.setup(1920,1080,0,0)
turtle.pencolor("red")
turtle.speed(1)

turtle.fillcolor("red") #绘制图形的填充颜色
turtle.pendown()
turtle.begin_fill() #准备开始填充图形


for turtle in range(0,5):
    turtle.forward(200)
    turtle.right(144)
turtle.end_fill() #停止填充


turtle.penup() #提起画笔