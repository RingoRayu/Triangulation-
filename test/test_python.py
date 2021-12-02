import cv2
import numpy as np
import random

def rect_contains(rect, point) :
    if point[0] < rect[0] :
        return False
    elif point[1] < rect[1] :
        return False
    elif point[0] > rect[2] :
        return False
    elif point[1] > rect[3] :
        return False
    return True

def draw_delaunay(img, subdiv, delaunay_color ) :

    triangleList = subdiv.getTriangleList()
    size = img.shape
    r = (0, 0, size[1], size[0])

    for t in triangleList :

        pt1 = (t[0], t[1])
        pt2 = (t[2], t[3])
        pt3 = (t[4], t[5])

        if rect_contains(r, pt1) and rect_contains(r, pt2) and rect_contains(r, pt3) :

            cv2.line(img, pt1, pt2, delaunay_color, 1, 16, 0)
            cv2.line(img, pt2, pt3, delaunay_color, 1, 16, 0)
            cv2.line(img, pt3, pt1, delaunay_color, 1, 16, 0)

if __name__ == "__main__" :
    IMAGE_WIDTH = 500
    IMAGE_HEIGHT = 500
    N_POINTS = 500

    img = np.zeros(
        (IMAGE_WIDTH, IMAGE_HEIGHT, 3),
        dtype=np.uint8
    )

    rect = (0, 0, IMAGE_WIDTH, IMAGE_HEIGHT)

    subdiv = cv2.Subdiv2D(rect)

    for i in range(N_POINTS):
        points = (
            random.randint(0 + 1, IMAGE_WIDTH - 1),
            random.randint(0 + 1, IMAGE_HEIGHT - 1)
        )
        subdiv.insert(points)

    draw_delaunay(img, subdiv, (255, 255, 255))

    cv2.imshow('result', img)

    k = cv2.waitKey(0)

    cv2.destroyAllWindows()
