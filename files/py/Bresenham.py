import matplotlib.pyplot as plt

plt.title("Bresenham Algorithm")
plt.xlabel("X - Axis")
plt.ylabel("Y - Axis")

def bresenham(x1,y1,x2,y2):
  x,y = x1,y1
  dx = abs(x2-x1)
  dy = abs(y2-y1)

  gradient = dy/float(dx)

  if gradient > 1:
    dx, dy = dy, dx
    x, y = y, x
    x1, y1 = y1, x1
    x2, y2 = y2, x2

  p = 2*dy + dx

  print("x = ",x,"y = ",y)

  # initializing the plotting points

  xcordinates = [x]
  ycordinates = [y]

  for k in range(2,dx):
    if p > 0:
      y = y + 1 if y<y2 else y-1
      p = p + 2 * (dy - dx)
    else:
      p = p + 2 * dy
    x = x+1 if x<x2 else x-1

    print("x = ",x,"y = ",y)
    xcordinates.append(x)
    ycordinates.append(y)

  plt.plot(xcordinates,ycordinates)
  plt.show()

def main():
  x1 = int(input("Enter x1 value"))
  x2 = int(input("Enter x2 value"))
  y1 = int(input("Enter y1 value"))
  y2 = int(input("Enter y2 value"))

  bresenham(x1,y1,x2,y2)

if __name__ == "__main__":
  main()