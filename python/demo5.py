import turtle
turtle.setup(1920,1080,0,0)
turtle.color("red")
turtle.begin_fill()
for i in range(5):
    turtle.pd()
    turtle.fillcolor("red")
    turtle.fd(300)
    turtle.right(144)
turtle.end_fill()
turtle.done()

