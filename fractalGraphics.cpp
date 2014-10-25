void drawLine(Point first, Point second, const float color[])
{
    glColor3fv(color);
    glBegin(GL_LINES);
        glVertex2i(first.x, first.y);
        glVertex2i(second.x, second.y);
    glEnd();
    glFlush();
}

void drawPolygon(Point poly[], int size, const float color[])
{
    int i;

    for(i = 0; i < size; ++i)
    {
        //draw a line between each pair of points
        drawLine(poly[i], poly[(i+1)%size]/*, add color*/);
    }

}




