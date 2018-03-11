#include <cg_utils.h>
#include "cg_test.hpp"
#include <cg_gem3d.h>

const GLsizei WinWidth = 800;
const GLsizei WinHeight = 600;

void renderWireTeapot() {
    //glShadeModel(GL_SMOOTH); 
    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3f(1.0,1.0,0);
    glutWireTeapot(3);
    glFlush();
}

void renderLineSegment() {
    glClear(GL_COLOR_BUFFER_BIT); //清除窗口
    glColor3f(1.0, 0.0, 0.0); //红色线段
    glBegin (GL_LINES); //开始绘制线段
      glVertex2i(280, 20); //顶点1
      glVertex2i(20, 180); //顶点2
    glEnd(); //结束绘制
    glFlush(); //强制清空所有缓存，并处理OpenGL函数
    errorCheck();
}

void renderPoints() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_POINTS);
      glVertex2i(280, 20);
      glVertex2i(20, 20);
      glVertex2i(150, 180);
    glEnd();

    glFlush();
}

void renderPointsV() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    int point1[] = {280, 20};
    int point2[] = {20, 20};
    int point3[] = {150, 180};

    glBegin(GL_POINTS);
      glVertex2iv(point1);
      glVertex2iv(point2);
      glVertex2iv(point3);
    glEnd();

    glFlush();
}

void renderTriangle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    int p1[] = {20, 20};
    int p2[] = {280, 20};
    int p3[] = {150, 180};


    /* GL_LINES: 连接每一对相邻顶点
    glBegin(GL_LINES);
      glVertex2iv(p1);
      glVertex2iv(p2);

      glVertex2iv(p1);
      glVertex2iv(p3);
      
      glVertex2iv(p2);
      glVertex2iv(p3);
    glEnd();
    */

    /* GL_LINE_STRIP: 生成折线，从第一个端点到最后一个端点依次首尾相连  
    glBegin(GL_LINE_STRIP);
      glVertex2iv(p1);
      glVertex2iv(p2);
      glVertex2iv(p3);
      glVertex2iv(p4);
    glEnd();
    */

    /* GL_LINE_LOOP: 生成封闭折线，自动连接最后和第一个端点 */  
    glBegin(GL_LINE_LOOP);
      glVertex2iv(p1);
      glVertex2iv(p2);
      glVertex2iv(p3);
    glEnd();
    
    glFlush();
}

void renderLineDDA() {
    glClear(GL_COLOR_BUFFER_BIT); //清除窗口
    glColor3f(0.0, 0.0, 1.0); //蓝色线段
    lineDDA(280, 20, 20, 180);
    glColor3f(0.0, 1.0, 0.0); //绿色线段
    lineDDA(20, 20, 280, 180);
    glFlush();
}

void renderLineBres() {
    glClear(GL_COLOR_BUFFER_BIT); //清除窗口
    glColor3f(0.0, 0.0, 0.0); //黑色线段
    lineBres(20, 20, 280, 180);
    glFlush();
}

void renderCircleMidPoint() {
    glClear(GL_COLOR_BUFFER_BIT); //清除窗口
    glColor3f(1.0, 0.0, 1.0); //品红色线条
    circleMidPoint(WinWidth / 2, WinHeight / 2, WinHeight / 2 - 10);
    glFlush();
}

void renderEllipseMidPoint() {
    glClear(GL_COLOR_BUFFER_BIT); //清除窗口
    glColor3f(0.5, 0.0, 0.0); //深红色线条
    ellipseMidPoint(WinWidth / 2, WinHeight / 2, 300 , 150);
    glFlush();
}

void renderRegPolygon() {
    glClear(GL_COLOR_BUFFER_BIT);
    Vec2i c(WinWidth / 2, WinHeight / 2);
    Color4f color(1.0, 0.0, 1.0, 1.0);
    regPolygon(c, 200, 12, color);
    glFlush();
}

void renderColoredTriangle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);

    //填充模式(默认)
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2i(50, 50);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2i(WinWidth / 2, WinHeight - 50);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2i(WinWidth - 50, 50);
    glEnd();
    //线框模式
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(3.0);
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 0.0);
        //第一个顶点
        glVertex2i(WinWidth / 2, WinHeight - 50);       
        //glColor3f(1.0, 0.0, 0.0);
        //消除第二条边
        glEdgeFlag(GL_FALSE);
        //第二个顶点 
        glVertex2i(50, 50);
        //glColor3f(0.0, 1.0, 0.0);
        //显示第三条边
        glEdgeFlag(GL_TRUE);
        //第三个顶点
        glVertex2i(WinWidth - 50, 50);
    glEnd();

    glFlush();
}

void test2d() {
    cg::Vec3f v1(1.0);
    cg::Vec3f v2(2);
    //cout << v1 << v2 << endl;
    v1 + v2;
    cout << v1 - v2;
    openWindow("CG with OpenGL", renderLineDDA, WinWidth, WinHeight);
}