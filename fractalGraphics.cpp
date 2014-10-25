void drawLine(point first, point second)
{
    glBegin(LINES);
        glVertex2i(first.x, first.y);
        glVertex2i(second.x, second.y);
    glEnd();
}

void drawPolygon(point poly[])
{

}
