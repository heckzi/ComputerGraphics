////// lab 04
////
////#include <gl/glut.h>
////#include <stdio.h>
////#include <string.h>
////
////bool antialiase_on = FALSE;
////bool blend_on = FALSE;
////
////GLint point_x[150];
////GLint point_y[150];
////int draw_mode = 0;
////int draw_type[50] = { 0 };
////int num = 0; // ������ �޴�
////int num_p = 0; // ���콺�� ���� ���� �� ��°���� ��Ÿ���� index ����
////int a = 0;
////
////void init(void)
////{
////    /* ȭ���� �⺻������ blue ���� */
////    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
////
////    /* ȭ�� ��ǥ ���� ���� */
////    glMatrixMode(GL_PROJECTION);
////    glLoadIdentity();
////    gluOrtho2D(0.0f, 500.0f, 0.0f, 500.0f);
////
////    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
////    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
////    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
////    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
////}
////
////void draw_string(void* font, const char* str, int x, int y) {
////    unsigned int i;
////    glRasterPos2i(x, y);
////    for (i = 0; i < strlen(str); i++) {
////        glutBitmapCharacter(font, str[i]);
////    }
////}
////void draw(void)
////{
////    glClear(GL_COLOR_BUFFER_BIT);
////    int i = 0, i_p = 0;
////    while (draw_type[i] != 0) {
////        if (draw_type[i] == 1) {
////            glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
////            glPointSize(10.0f);
////            glBegin(GL_POINTS);
////            glVertex2i(point_x[i_p], point_y[i_p]);
////            glEnd();
////            i_p++;
////        }
////        else if (draw_type[i] == 2) {
////            glLineWidth(3.0f);
////            glColor4f(1.0f, 1.0f, 0.0f, 0.5f);
////            glBegin(GL_LINES);
////            glVertex2i(point_x[i_p], point_y[i_p]);
////            glVertex2i(point_x[i_p + 1], point_y[i_p + 1]);
////            glEnd();
////            i_p += 2;
////        }
////        else if (draw_type[i] == 3) {
////            glLineWidth(4.0f);
////            glColor3f(1.0f, 0.0f, 0.0f);
////            glBegin(GL_TRIANGLES);
////            glVertex2i(point_x[i_p], point_y[i_p]);
////            glVertex2i(point_x[i_p + 1], point_y[i_p + 1]);
////            glVertex2i(point_x[i_p + 2], point_y[i_p + 2]);
////            glEnd();
////            i_p += 3;
////        }
////        i++;
////    }
////    glColor3f(1.0f, 1.0f, 0);
////    draw_string(GLUT_BITMAP_TIMES_ROMAN_24, "Graphics are cool!!", 10, 10);
////    draw_string(GLUT_BITMAP_HELVETICA_18, "I Like Computer Graphics!!", 250, 475);
////    glFlush();
////}
////void sub_menu_function(int option) {
////    printf("Submenu %d has been selected\n", option);
////    if (option == 1) {
////        draw_mode = 1; // ��
////    }
////    else if (option == 2) {
////        draw_mode = 2; // ��
////    }
////    else if (option == 3) {
////        draw_mode = 3; // �ﰢ��
////    }
////}
////
////void main_menu_function(int option) {
////    printf("Main menu %d has been selected\n", option);
////    if (option == 999) {
////        exit(0);
////    }
////    else if (option == 11) {
////        glClear(GL_COLOR_BUFFER_BIT);
////        memset(draw_type, 0, sizeof(draw_type));
////        a = 0;
////        num_p = 0;
////        num = 0;
////        draw_mode = 0;
////        glFlush();
////    }
////}
////
////void mouse(int button, int state, int x, int y) {
////    if (button == GLUT_LEFT_BUTTON) {
////        if (draw_mode == 0) {
////            printf("draw mode is 0, no change\n");
////            return;
////        }
////        if (state == GLUT_DOWN) {
////            printf("Mouse button is clicked! (%d, %d)\n", x, y);
////            draw_type[num] = draw_mode;
////
////            point_x[num_p] = x;
////            point_y[num_p] = 500 - y;
////            num_p++;
////            a++;
////        }
////    }
////    if (a >= draw_mode) {
////        num++;
////        a = 0;
////        glutPostRedisplay();
////    }
////
////}
////
////void keyboard(unsigned char key, int  x, int y) {
////    printf("You pressed %c\n", key);
////    if (key == 'a') {
////        antialiase_on = !antialiase_on;
////    }
////    if (antialiase_on)
////    {
////        printf("Antialiasing On \n");
////        glEnable(GL_POINT_SMOOTH); //anti 
////        glEnable(GL_LINE_SMOOTH); //anti 
////        glEnable(GL_POLYGON_SMOOTH); //anti 
////    }
////    else {
////        printf("Antialiasing Off \n");
////        glDisable(GL_POINT_SMOOTH);
////        glDisable(GL_LINE_SMOOTH);
////        glDisable(GL_POLYGON_SMOOTH);
////    }
////
////    if (key == 'b') {
////        blend_on = !blend_on;
////    }
////    if (blend_on) {
////        printf("Blending On \n");
////        glEnable(GL_BLEND); // blend
////        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
////    }
////    else {
////        printf("Blending Off \n");
////        glDisable(GL_BLEND);
////    }
////    glutPostRedisplay();
////}
////int main(int argc, char** argv)
////{
////    int submenu1;
////    /* Window �ʱ�ȭ */
////    glutInit(&argc, argv);
////    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
////    glutInitWindowSize(500, 500);
////    glutInitWindowPosition(300, 300);
////    glutCreateWindow("Lab-4");
////    init(); // -> ����� �ʱ�ȭ �Լ�
////
////    /* Popup menu ���� �� �߰� */
////    submenu1 = glutCreateMenu(sub_menu_function);
////    glutAddMenuEntry("point", 1);
////    glutAddMenuEntry("line", 2);
////    glutAddMenuEntry("triangle", 3);
////
////    glutCreateMenu(main_menu_function);
////    glutAddMenuEntry("Quit", 999);
////    glutAddMenuEntry("Clear!", 11);
////    glutAddSubMenu("Sub Menu", submenu1);
////    glutAttachMenu(GLUT_RIGHT_BUTTON);
////
////    /* Popup menu ���� �� �߰� �� */
////
////
////     /* Callback �Լ� ���� */
////    glutMouseFunc(mouse);
////    glutKeyboardFunc(keyboard);
////    glutDisplayFunc(draw); /* draw() -> ���� �׸��� �Լ� */
////
////
////    /* Looping ���� */
////    glutMainLoop();
////
////    return 0;
////}
//#include <gl/glut.h>
//#include <stdio.h>
//#include <cmath>
//#include <GL/freeglut.h>
//
//// ����, ȭ��, �� ,�¾�, �ݼ� ����
//float rotating_angle[5] = {0,0,0,0,0}; // ����
//float revolution_angle[5] = {0,0,0,0,0}; // ����
//bool spin_state = true;
//void init(void)
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//
//     // Light ����
//    GLfloat light_ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
//    GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
//    GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
//
//    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//
//    GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
//    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//    glMateriali(GL_FRONT, GL_SHININESS, 64);
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//    glEnable(GL_COLOR_MATERIAL);
//    
//	glMatrixMode(GL_PROJECTION);
//}
//void resize(int width, int height){
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (float)width/(float)height, 1, 500);
//	glMatrixMode(GL_MODELVIEW);
//}
//void draw_axis(void) {
//	glLineWidth(3); 
//	glBegin(GL_LINES);
//      glColor3f(1, 0, 0);
//      glVertex3f(0, 0, 0);
//      glVertex3f(4, 0, 0);
//
//      glColor3f(0, 1, 0);
//      glVertex3f(0, 0, 0);
//      glVertex3f(0, 4, 0);
//
//	  glColor3f(0, 0, 1); 
//	  glVertex3f(0, 0, 0); 
//	  glVertex3f(0, 0, 4);
//	glEnd();
//	glLineWidth(1);
//}
//
//void draw(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(10, 10, 10, 0, 0, 0, 0, 1, 0);
//
//	// SUN
//	glRotatef(rotating_angle[3], 0, 1, 0);
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glutSolidSphere(2, 50, 50);
//	draw_axis();
//
//	glPushMatrix(); // ������ ����� ���ÿ� ����
//	// Earth
//    glRotatef(rotating_angle[0], 0, 1, 0);
//    glTranslatef(5, 0, 0);
//    glRotatef(revolution_angle[0], 0, 1, 0);
//	
//    glColor3f(0,0,1);
//    glutSolidSphere(1, 20, 20);
//
//	// Moon : ���� �������� �����ؾ��ϴϱ� Popmatrix ���ϱ�
//	glRotatef(rotating_angle[2], 0, 1, 0);
//    glTranslatef(2, 0, 0);
//    glRotatef(revolution_angle[2], 0, 1, 0);
//
//	glColor3f(0,0.5,1);
//    glutSolidSphere(0.3, 20, 20);
//	
//	// Mars
//	glPopMatrix(); // �¾��� �׷��� ���� ���·� ��� ����
//	glPushMatrix();
//	glRotatef(rotating_angle[1], 0, 1, 0);
//    glTranslatef(8, 0, 0);
//    glRotatef(revolution_angle[1], 0, 1, 0);
//
//    glColor3f(1,1,1);
//    glutSolidSphere(1, 20, 20);
//
//	// Venus
//	glPopMatrix();
//	glRotatef(rotating_angle[4], 0, 1, 0);
//    glTranslatef(2, 0, 0);
//    glRotatef(revolution_angle[4], 0, 1, 0);
//
//    glColor3f(1,0,1);
//    glutSolidSphere(1, 10, 10);
//
//
//	glFlush();
//	glutSwapBuffers(); //double buffering ��
//}
//
//void idle(void){
//	if (spin_state==true){
//		rotating_angle[0] = rotating_angle[0] + 0.01;
//    if (rotating_angle[0] > 360) rotating_angle[0] -= 360;
//    revolution_angle[0] = revolution_angle[0] + 0.3;
//    if (revolution_angle[0] > 360) revolution_angle[0] -= 360;
//
//	rotating_angle[1] = rotating_angle[1] + 0.05;
//    if (rotating_angle[1] > 360) rotating_angle[1] -= 360;
//    revolution_angle[1] = revolution_angle[1] + 0.4;
//    if (revolution_angle[1] > 360) revolution_angle[1] -= 360;
//
//	rotating_angle[2] = rotating_angle[2] + 0.01;
//    if (rotating_angle[2] > 360) rotating_angle[2] -= 360;
//    revolution_angle[2] = revolution_angle[2] + 0.05;
//    if (revolution_angle[2] > 360) revolution_angle[2] -= 360;
//
//	rotating_angle[3] = rotating_angle[3] + 0.02;
//    if (rotating_angle[3] > 360) rotating_angle[3] -= 360;
//
//	rotating_angle[4] = rotating_angle[4] + 0.01;
//    if (rotating_angle[4] > 360) rotating_angle[4] -= 360;
//    revolution_angle[4] = revolution_angle[4] + 0.4;
//    if (revolution_angle[4] > 360) revolution_angle[4] -= 360;
//	}
//	
//	glutPostRedisplay();
//}
//
//void special_keyboard(unsigned char key, int x, int y) {
//    if(key == 's'){
//		if(spin_state == false) spin_state = true;
//		else spin_state = false;
//	}
//}
//
//int main(int argc, char** argv)
//{
//	/* Window �ʱ�ȭ */
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500); 
//	glutInitWindowPosition(300, 300); 
//	glutCreateWindow("My First GL Program"); 
//	init(); // -> ����� �ʱ�ȭ �Լ�
//
//	/* Popup menu ���� �� �߰� �� */
//	/* Callback �Լ� ���� */ 
//	glutDisplayFunc(draw); /* draw() -> ���� �׸��� �Լ� */
//	glutReshapeFunc(resize);
//	glutKeyboardFunc(special_keyboard);
//
//	glutIdleFunc(idle); // ���� �ð��� �� ��
//
//	/* Looping ���� */ 
//	glutMainLoop();
//
//	return 0;
//}
