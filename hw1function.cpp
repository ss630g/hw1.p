#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <GL/glx.h>
const int MAX_PARTICLES = 100;
struct Vec {
    float x, y, z;
};

struct Shape {
    float width, height;
    float radius;
    Vec center;
};

struct Particle {
    Shape s;
    Vec velocity;
};

class Game {
    public:
        Shape box, circle;
        Particle particle[MAX_PARTICLES];
        int n;
        Game() {
            n = 0;
        }
};

void render(Game *game)
{
    float w, h;
    glClear(GL_COLOR_BUFFER_BIT);
    //Draw shapes...

    //draw box


    Shape *b;
    glColor3ub(100,20,70);
    b = &game->box;
    glPushMatrix();
    glTranslatef(b->center.y-100, b->center.x-50, b->center.z);
    w = b->width;
    h = b->height;
    glBegin(GL_QUADS);
    glVertex2i( -w,-h);
    glVertex2i( -w, h);
    glVertex2i( w, h);
    glVertex2i( w,-h);
    glEnd();
    glPopMatrix();




    Shape *g;
    //  glColor3ub(90,140,90);
    glColor3ub(125,50,100);
    g = &game->box;
    glPushMatrix();
    glTranslatef(g->center.y-10, g->center.x-120, g->center.z);
    w = g->width;
    h = g->height;
    glBegin(GL_QUADS);
    glVertex2i( -w,-h);
    glVertex2i( -w, h);
    glVertex2i( w, h);
    glVertex2i( w,-h);
    glEnd();
    glPopMatrix();

    Shape *o;
    glColor3ub(10,100,70);
    o = &game->box;
    glPushMatrix();
    glTranslatef(o->center.y+140, o->center.x-190, o->center.z);
    w = o->width;
    h = o->height;
    glBegin(GL_QUADS);
    glVertex2i( -w,-h);
    glVertex2i( -w, h);
    glVertex2i( w, h);
    glVertex2i( w,-h);
    glEnd();
    glPopMatrix();

    Shape *s;
    //  glColor3ub(90,140,90);
    glColor3ub(70,100,50);
    s = &game->box;
    glPushMatrix();
    glTranslatef(s->center.x, s->center.y, s->center.z);
    w = s->width;
    h = s->height;
    glBegin(GL_QUADS);
    glVertex2i(-w,-h);
    glVertex2i(-w, h);
    glVertex2i( w, h);
    glVertex2i( w,-h);
    glEnd();
    glPopMatrix();


    Shape *c;
    glColor3ub(45,50,130);
    c = &game->box;
    glPushMatrix();
    glTranslatef(c->center.x+130, c->center.y-60, c->center.z);
    w = c->width;
    h = c->height;
    glBegin(GL_QUADS);
    glVertex2i( -w,-h);
    glVertex2i( -w, h);
    glVertex2i( w, h);
    glVertex2i( w,-h);
    glEnd();
    glPopMatrix();

    /* float tp = 2.0f * 3.14159f;
       int t = 20;

       Shape * e;
       e = &game->circle;
       r = e->radius;

       glColor3ub(100,10,10);
       glPushMatrix();
       glTranslatef(c->center.x, c->center.y, c->center.z);
    // w = c->width;
    // h = c->height;
    glBegin(GL_TRIANGLE_FAN);


    glVertex2f(0.0f, 0.0f);

    for( int i = 0; i <= t; i++) {
    glVertex2f(r * cos(i * tp / t), r * sin(i * tp / t));
    }

    glEnd();
    glPopMatrix();

*/





    //draw all particles here
    for (int i=0; i<game->n ; i++) {
        Vec *c = &game->particle[i].s.center;
        glPushMatrix();
        glColor3ub( 170 , 160 , 170);
        //glColor3ub(100,160,200);
        w = 2;
        h = 2;
        glBegin(GL_QUADS);
        glVertex2i(c->x-w, c->y-h);
        glVertex2i(c->x-w, c->y+h);
        glVertex2i(c->x+w, c->y+h);
        glVertex2i(c->x+w, c->y-h);
        glEnd();
        glPopMatrix();
    }
}

