//#include <gl/glut.h>
//#include <stdio.h>
//#include <windows.h>
//#include<GL/freeglut.h>
//#include<cmath>
//
//void init(void)
//{
//	/* 화면의 기본색 설정 */
//	glClearColor(0.3f, 0.0f, 0.5f, 1.0f);
//	glMatrixMode(GL_PROJECTION);
//}
//
//void draw_axis(void)
//{
//	glLineWidth(3); // 좌표축의 두께
//	glBegin(GL_LINES);
//	glColor3f(1, 0, 0); // X축은 red
//	glVertex3f(0, 0, 0);
//	glVertex3f(4, 0, 0);
//	glColor3f(0, 1, 0); // Y축은 green
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 4, 0);
//	glColor3f(0, 0, 1); // Z축은 blue
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 0, 4);
//	glEnd();
//	glLineWidth(1); // 두께 다시 환원
//}
//void draw_triangle(void)
//{
//	/* 면의 색상을 설정으로 */
//	glColor3f(0.7f, 0.5f, 0.3f);
//	glBegin(GL_TRIANGLES); //STRIP으로 도형을 그림
//	glVertex3i(3, -2, 1);
//	glVertex3i(-5, 3, -1);
//	glVertex3i(0, 3, -1);
//	glEnd();
//}
//void draw(void) // 기존 함수 변경
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	//카메라위치, 바라보는 점, Upvector 순서
//	gluLookAt(7, 5, 8, 0, 0, 0, 0, 1, 0);
//	glTranslatef(0, 1, 0);
//	draw_triangle();
//
//	glTranslatef(0, -1, 0);
//	draw_axis();
//	glFlush();
//	glutSwapBuffers(); // double buffering시
//}
//void resize(int width, int height)
//{
//	glViewport(0, 0, 800, 600);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, 4.0 / 3.0,
//		1, 50);
//	glMatrixMode(GL_MODELVIEW);
//}
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(800, 600);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("12191781 손혁진");
//	init();
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	glutMainLoop();
//
//	return 0;
//}
