#ifndef UI_H
#define UI_H

void InitUI(float maxPlayerHealth, char maxLife);

void DrawUI(float wWidth, float wHeight);
void UpdateUIPlayerHealth(float newHealth);
void UpdateUIPlayerLife(char numCurrentLife);
void UpdateUIPlayerScore(unsigned int newScore);


#endif // UI_H