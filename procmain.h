#ifndef PROCMAIN_H_INCLUDED
#define PROCMAIN_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "parent.h"
#include "child.h"
#include "relation.h"

using namespace std;

void menu(int &pil);
void edit(List_celeb &C,List_followers &F);
void sorting(List_celeb &C, List_followers &F);
#endif // PROCMAIN_H_INCLUDED
