#include "Terrain.h"

char Water::symbol() const { return '~'; }
char Plain::symbol() const { return '.'; }
char Mountain::symbol() const { return '#'; }
char Snow::symbol() const { return 'S'; }
