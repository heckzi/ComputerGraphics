//#include <gl/glut.h>
//#include <stdio.h>
//#include <windows.h>
//#include<GL/freeglut.h>
//
//float sun_rot = 0;
//float planet_rot[5] = {}; //���� ��
//float planet_rev[5] = {}; //���� ��
//float moon_rot = 0;
//float moon_rev = 0;
//bool switch_rot = true;
//int light_state = 0;
//void idle(void)
//{ 
//	if (switch_rot == true) {
//	//������ �Ϸ絿�� �����ϴ� ���� 0.001���� �����ϰ� �뷫 ���
//
//	//��������
//		sun_rot = sun_rot + 0.007; //�¾�
//		if (sun_rot > 360) sun_rot -= 360;
//		planet_rot[0] = planet_rot[0] + 0.00016; //����
//		if (planet_rot[0] > 360) planet_rot[0] -= 360;
//		planet_rot[1] = planet_rot[1] + 0.00324; //�ݼ�
//		if (planet_rot[1] > 360) planet_rot[1] -= 360;
//		planet_rot[2] = planet_rot[2] + 0.036; //����
//		if (planet_rot[2] > 360) planet_rot[2] -= 360;
//		planet_rot[3] = planet_rot[3] + 0.00099; //ȭ��
//		if (planet_rot[3] > 360) planet_rot[3] -= 360;
//		moon_rot = moon_rot + 0.00075; //��
//		if (moon_rot > 360) moon_rot -= 360;
//
//		//��������
//		planet_rev[0] = planet_rev[0] + 0.00415; //����
//		if (planet_rev[0] > 360) planet_rev[0] -= 360;
//		planet_rev[1] = planet_rev[1] + 0.00324; //�ݼ�
//		if (planet_rev[1] > 360) planet_rev[1] -= 360;
//		planet_rev[2] = planet_rev[2] + 0.001; //����
//		if (planet_rev[2] > 360) planet_rev[2] -= 360;
//		planet_rev[3] = planet_rev[3] + 0.0005; //ȭ��
//		if (planet_rev[3] > 360) planet_rev[3] -= 360;
//		moon_rev = moon_rev + 0.00083; //��
//		if (moon_rev > 360) moon_rev -= 360;
//	}
//	
//	glutPostRedisplay();
//}
//void keyboard(unsigned char key, int x, int y)
//{
//	/* ���ڵ��� �ؼ��ؼ� ���ϴ� ����� ���� */
//	printf("You pressed %c\n", key);
//	if (key == '1') light_state = 1; //�¾�
//	if (key == '2') light_state = 2; //����
//	if (key == '3') light_state = 3; //��
//}
//void init(void)
//{
//	/* ȭ���� �⺻������ dark blue ���� */
//	glClearDepth(1.0f);
//	glEnable(GL_DEPTH_TEST);
//	glClearColor(0.3f, 0.0f, 0.5f, 1.0f);
//	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
//	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//	//GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };//ī�޶� ��ġ�� ���� ��ġ �ϰ�
//	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//
//	// glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 45.0); //cutoff �ϴ� ��
//	// GLfloat spot_direction[] = { 1.0, 0.0, 1.0, 0.0 }; 
//	// glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
//	// glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 3.0);
//	
//	//glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 2.0); // ����Ӽ�
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialf(GL_FRONT, GL_SHININESS, 64);
//	
//	//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); //���� �츮��
//	//glEnable(GL_COLOR_MATERIAL);	
//
//	glMatrixMode(GL_PROJECTION);
//	//
//}
//void resize(int width, int height)
//{
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (float)width / (float)height,
//		1, 500);
//	glMatrixMode(GL_MODELVIEW);
//}
//void draw_axis(void)
//{
//	glLineWidth(3); // ��ǥ���� �β�
//	glBegin(GL_LINES);
//	glColor3f(1, 0, 0); // X���� red
//	glVertex3f(0, 0, 0);
//	glVertex3f(4, 0, 0);
//	glColor3f(0, 1, 0); // Y���� green
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 4, 0);
//	glColor3f(0, 0, 1); // Z���� blue
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 0, 4);
//	glEnd();
//	glLineWidth(1); // �β� �ٽ� ȯ��
//}
//void draw(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(15, 15, 15, 0, 0, 0, 0, 1, 0);
//	GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };
//
//	//�¾� �׸���
//	if(light_state ==1) glLightfv(GL_LIGHT0, GL_POSITION, light_position);//�¾��� �߽ɿ� ������ġ�ϰ�
//	glRotatef(sun_rot, 0, 1, 0);
//	glColor3f(1, 0, 0);
//	glutSolidSphere(2.0, 50, 50);
//	draw_axis();
//	glPushMatrix();
//
//	//���� �׸���
//	glPopMatrix();
//	glPushMatrix();
//	glRotatef(planet_rev[0], 0, 1, 0);
//	glTranslatef(3, 0, 0);
//	glRotatef(planet_rot[0], 0, 1, 0);
//	glColor3f(0.3, 0.6, 0);
//	glutSolidSphere(0.3, 50, 50);
//
//	//�ݼ� �׸���
//	glPopMatrix();
//	glPushMatrix();
//	glRotatef(planet_rev[1], 0, 1, 0);
//	glTranslatef(4, 0, 0);
//	glRotatef(planet_rot[1], 0, 1, 0);
//	glColor3f(0.4, 0.6, 0.5);
//	glutSolidSphere(0.3, 50, 50);
//
//	//���� �׸���
//	glPopMatrix();
//	glPushMatrix();
//	glRotatef(planet_rev[2], 0, 1, 0);
//	glTranslatef(6, 0, 0);
//	glRotatef(planet_rot[2], 0, 1, 0);
//	if (light_state == 2) glLightfv(GL_LIGHT0, GL_POSITION, light_position); //������ �߽ɿ� ������ġ�ϰ�
//	glColor3f(0, 0.1, 0.9);
//	glutSolidSphere(1.0, 50, 50);
//
//	//�� �׸���
//	glRotatef(moon_rev, 0, 1, 0);
//	glTranslatef(1.5, 0, 0); 
//	glRotatef(moon_rot, 0, 1, 0); 
//	if (light_state == 3) glLightfv(GL_LIGHT0, GL_POSITION, light_position);  //���� �߽ɿ� ������ġ�ϰ�
//	glColor3f(0, 0.5, 1);
//	glutSolidSphere(0.2, 50, 50);
//
//	//ȭ�� �׸���
//	glPopMatrix();
//	glRotatef(planet_rev[3], 0, 1, 0);
//	glTranslatef(9, 0, 0);
//	glRotatef(planet_rot[3], 0, 1, 0);
//	glColor3f(1.0, 0, 0.3);
//	glutSolidSphere(1.0, 50, 50);
//
//	glFlush();
//	glutSwapBuffers();
//}
//void main_menu_function(int option)
//{
//	if (option == 999) {
//		printf("Quit menu has been selected\n");
//		exit(0);
//	}
//	if (option == 1) {
//		printf("Rotate Switch menu has been selected\n");
//		switch_rot = switch_rot ? false : true;
//	}
//}
//int main(int argc, char** argv)
//{
//	/* Window �ʱ�ȭ */
//	glutInit(&argc, argv);
//	int mainmenu;
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("12191781 ������ 6����");
//	init(); // -> ����� �ʱ�ȭ �Լ�
//
//
//	glutCreateMenu(main_menu_function);
//	glutAddMenuEntry("Quit", 999);
//	glutAddMenuEntry("Rotate Switch", 1);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	/* Callback �Լ� ���� */
//	glutIdleFunc(idle);
//	glutKeyboardFunc(keyboard);
//	glutDisplayFunc(draw);
//	glutReshapeFunc(resize);
//	/* Looping ���� */
//	glutMainLoop();
//	return 0;
//}
//
