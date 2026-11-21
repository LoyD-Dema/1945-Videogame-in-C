#ifndef UI_H
#define UI_H

void InitUI(float maxPayerHealth, char numOfLife);

void DrawUI(float wWidth, float wHeight);
void UpdateUIPlayerHealth(float newHealth);
void UpdateUIPlayerLife(char numCurrentLife);
void UpdateUIPlayerScore(int newScore);


#endif // UI_H