//#include <windows.h>
//#include <gl/glut.h>
//#include <stdio.h>
//float g_pPosition[6] = { 0.0f, 144.0f, -100.0f, -100.0f, 100.0f, -100.0f };
//int g_nX, g_nY;
//int g_nSelect = 0;
//int g_nGLWidth = 500, g_nGLHeight = 500;
//
//void init(void) {
//	glClearColor(0.0, 0.0, 0.0, 1.0);
//	glClearDepth(1.0f);
//	glEnable(GL_DEPTH_TEST);
//	GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
//	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialf(GL_FRONT, GL_SHININESS, 64);
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//	glEnable(GL_COLOR_MATERIAL);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-g_nGLWidth / 2.0f, g_nGLWidth / 2.0f, -g_nGLHeight / 2.0f,
//		g_nGLHeight / 2.0f, -100, 100);
//}
//void DrawBackground()
//{
//	glPushAttrib(GL_ALL_ATTRIB_BITS);
//	glDisable(GL_LIGHTING);
//	glColor3f(1.0f, 1.0f, 1.0f);
//	int i;
//	int offset = 50;
//	glBegin(GL_LINES);
//	for (i = -g_nGLWidth / 2.0f; i < g_nGLWidth / 2.0f; i += offset)
//	{
//		glVertex3f(i, -g_nGLHeight / 2.0f, 0.0f);
//		glVertex3f(i, g_nGLHeight / 2.0f, 0.0f);
//	}
//	for (i = -g_nGLHeight / 2.0f; i < g_nGLHeight / 2.0f; i += offset)
//	{
//		glVertex3f(-g_nGLWidth / 2.0f, i, 0.0f);
//		glVertex3f(g_nGLWidth / 2.0f, i, 0.0f);
//	}
//	glEnd();
//	glPopAttrib();
//}
//void DrawSphere()
//{
//	glLoadName(1);
//	glPushMatrix();
//	glTranslatef(g_pPosition[0], g_pPosition[1], 0.0f);
//	glColor3f(1, 0, 0);//R
//	glutSolidSphere(25.0f, 30, 30);
//	glPopMatrix();
//	glLoadName(2);
//	glPushMatrix();
//	glTranslatef(g_pPosition[2], g_pPosition[3], 0.0f);
//	glColor3f(0, 1, 0);//G
//	glutSolidSphere(25.0f, 30, 30);
//	glPopMatrix();
//	glLoadName(3);
//	glPushMatrix();
//	glTranslatef(g_pPosition[4], g_pPosition[5], 0.0f);
//	glColor3f(0, 0, 1);//B
//	glutSolidSphere(25.0f, 30, 30);
//	glPopMatrix();
//}
//void draw(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	DrawBackground();
//	DrawSphere();
//	glFlush();
//	glutSwapBuffers();
//}
//void resize(int width, int height)
//{
//	g_nGLWidth = width;
//	g_nGLHeight = height;
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-width / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f,
//		-100, 100);
//	glMatrixMode(GL_MODELVIEW);
//}
//void Picking(int x, int y)
//{
//	GLuint selectBuf[256];
//	// first step
//	glSelectBuffer(256, selectBuf); //hit record를 저장할 공간지정
//	// second step
//	glRenderMode(GL_SELECT);//렌더링모드를 선택모드로 지정
//	// third step
//	glInitNames();//name stack을 초기화
//	glPushName(-1);//name stack을 초기화
//	// third step
//	GLint viewport[4];
//	glGetIntegerv(GL_VIEWPORT, viewport);
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity();
//	// fourth step
//	gluPickMatrix(x, y, 0.1, 0.1, viewport);
//
//	glOrtho(-g_nGLWidth / 2.0f, g_nGLWidth / 2.0f, -g_nGLHeight / 2.0f,
//		g_nGLHeight / 2.0f, -100, 100);
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//	DrawSphere(); //포지션을 바꾸면서 그려지는 구를 그리는 부분이다.
//	glPopMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glPopMatrix();
//	glFlush();
//	GLint hits = glRenderMode(GL_RENDER);
//	// sixth step
//	if (hits <= 0) return;
//	int stack = selectBuf[0]; //name stack에 있는 name의 갯수
//	unsigned int zMin = selectBuf[1];
//	unsigned int zMax = selectBuf[2];
//	g_nSelect = selectBuf[3]; //hit되었을때 namestack에 존재하는 name들이 아래부터 저장
//	int index = 3 + stack;
//	int i;
//	for (i = 1; i < hits; i++) { //제일 중요한 부분, zMin으로는 가장 가까운것부터 누르게할 수 있다. selectbuf[1]로 설정해서 하면된다.
//		stack = selectBuf[index];
//		if (zMin > selectBuf[index + 2]) {
//			zMin = selectBuf[index + 2];
//			g_nSelect = selectBuf[index + 3];
//		}
//		index += 3 + stack;
//	}
//	printf("\nHit된 공의 갯수 : %d\n", hits);
//	printf("선택된 공의 Name : %d\n", g_nSelect);
//}
//void mouse(int button, int state, int x, int y) {
//	y = g_nGLHeight - y;
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		Picking(x, y);
//		g_nX = x;
//		g_nY = y;
//	}
//	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//	{
//		g_nSelect = 0;
//	}
//}
//void motion(int x, int y) {
//	y = g_nGLHeight - y;
//	if (g_nSelect > 0) {
//		g_pPosition[(g_nSelect - 1) * 2 + 0] += x - g_nX;
//		g_pPosition[(g_nSelect - 1) * 2 + 1] += y - g_nY;
//		g_nX = x;
//		g_nY = y;
//		glutPostRedisplay();
//	}
//}
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitWindowSize(g_nGLWidth, g_nGLHeight);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("Picking");
//	init();
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	glutMouseFunc(mouse);
//	glutMotionFunc(motion);
//	glutMainLoop();
//	return 0;
//}