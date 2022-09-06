
#include"stm32f407xx.h"
void delayMs(int n);

int main (void){
/*Vamos a usar dos elementos aqui,el primero un boton k1= PE3 y el led d2=PA6*/
//inicializamos el reloj de PUERTO E Y DEL PUERTO A
	RCC->AHB1ENR|=(1<<0)|(1<<4);
	//CONFIGURAMOS LOS PINES COMO SALIDAS Y COMO ENTRADAS


	// PIN A6==  MODER =01 OTYPER=0 PUPDR=00
	GPIOA->MODER|=(1<<12);
	GPIOA->MODER &=~(1<<13);
	GPIOA->OTYPER &=~(1<<6);
	GPIOA->PUPDR &=~((1<<13)|(1<<12));

//PIN E3==    MODER =00  PUPDR=01
	GPIOE->MODER&=~((1<<7)|(1<<6));
	GPIOE->PUPDR&=~(1<<7);
	GPIOE->PUPDR|=(1<<6);

	// LOS LEDS TIENEN LOGICA NEGATIVA SE ENICENDEN CON UN CERO
	// Y LOS BOTONES PUSIMOS PULL -UP ,
	//SIN PRESION LA ENTRADA ES UN UNO Y CUANDO SE PULSAN VAN A CERO


	while(1){

		if (GPIOE->IDR & 0x8)

		GPIOA->ODR=0xF0;
		else

		GPIOA->ODR=0x00;
	}

}


void delayMs(int n) {
int i;
for (; n > 0; n--)
for (i = 0; i < 3195; i++) ; }


