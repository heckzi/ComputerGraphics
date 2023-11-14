//#include <gl/glut.h>
//#include <stdio.h>
//#include <windows.h>
//#include<GL/freeglut.h>
//#include<cmath>
//
//int selected_menu = 0;
//double radius = 20;
//double theta = 45, phi = 45;
//double cam[3];
//double center[3] = { 0,0,0 };
//double up[3] = { 0,1,0 };
//const double pi = 3.14;
//double m_RotateAngle = 0;
//
//void init(void)
//{
//	//추가해줘야함
//	glClearDepth(1.0f);
//
//	/* 화면의 기본색 설정 */
//	glClearColor(0.3f, 0.0f, 0.5f, 1.0f);
//	glMatrixMode(GL_PROJECTION);
//
//	// Light 설정 → 일단 그냥 이용
//	GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
//	GLfloat diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
//	GLfloat specularLight[] = { 0.9f, 0.9f, 0.9f, 1.0f };
//	GLfloat specularMaterial[] = { 1.0f, 1.0f, 1.0f,1.0f };
//	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
//	glMateriali(GL_FRONT, GL_SHININESS, 20);
//	glEnable(GL_COLOR_MATERIAL);
//
//	//뒷면 안그리기
//	//glEnable(GL_CULL_FACE);
//
//	//내부를 wireframe으로 표현
//	glPolygonMode(GL_BACK, GL_LINE);
//
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//
//	// Depth-Test Enable
//	glFrontFace(GL_CW); // Teapot은 CW로 정의됨
//	//glEnable(GL_DEPTH_TEST);
//}
//void idle(void) {
//	m_RotateAngle += 0.01;
//	glutPostRedisplay();
//
//	if (m_RotateAngle > 360) {
//		m_RotateAngle -= 360;
//		glutPostRedisplay();
//	}
//}
//void resize(int width, int height)
//{
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (float)width / (float)height,1, 500);
//	glMatrixMode(GL_MODELVIEW);
//}
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
//void mousewheel(int button, int dir, int x, int y) {
//	if (dir > 0) {
//		printf("Zoom In, ");
//		radius -= 1;
//		glutPostRedisplay();
//	}
//	else {
//		printf("Zoom Out, ");
//		radius += 1;
//		glutPostRedisplay();
//	}
//	printf("Direction: %d Radius: %f\n", dir, radius);
//}
//void draw(void) // 기존 함수 변경
//{
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	cam[0] = radius * sin(theta * pi / 180) * cos(phi * pi / 180);
//	cam[1] = radius * cos(theta * pi / 180);
//	cam[2] = radius * sin(theta * pi / 180) * sin(phi * pi / 180);
//	gluLookAt(cam[0], cam[1], cam[2],
//		center[0], center[1], center[2], up[0], up[1], up[2]);
//
//	//step2 평면으로 자르기
//	glPushMatrix();
//	glRotatef(m_RotateAngle, 0, 1, 0);
//	GLdouble eq[4] = { 1.0, 0.0, 0.0, 0.0 };
//	glClipPlane(GL_CLIP_PLANE0, eq);
//	glEnable(GL_CLIP_PLANE0);
//	glPopMatrix();
//
//	glColor3f(1, 1, 0);
//	glutSolidTeapot(4);
//	//draw_axis();
//	glFlush();
//}
//void main_menu_function(int option)
//{
//	printf("Main menu %d has been selected\n", option);
//	if (option == 999) {
//		exit(0);
//	}
//	if (option == 1) {
//		printf("Reset Teapot!\n");
//		radius = 20;
//		theta = 45;
//		phi = 45;
//		up[1] = 1;
//		glutPostRedisplay();
//	}
//}
//int main(int argc, char** argv)
//{
//	/* Window 초기화 */
//	glutInit(&argc, argv);
//
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("12191781 손혁진");
//	init(); // -> 사용자 초기화 함수
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAddMenuEntry("Reset", 1);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	/* Callback 함수 정의 */
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	glutMouseWheelFunc(mousewheel);
//	glutIdleFunc(idle);
//	/* Looping 시작 */
//	glutMainLoop();
//	return 0;
//}