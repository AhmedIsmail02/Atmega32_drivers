/*
 * GPIO.c

 *
 *  Created on: Nov 20, 2019
 *      Author: kino
 */
#include"util.h"
#include"stdtypes.h"
#include "GPIO.h"
unsigned long delay_A;
unsigned long delay_B;
unsigned long delay_C;
unsigned long delay_D;
unsigned long delay_E;
unsigned long delay_F;

void GPIO_Initialize_Port(PORT_ID port){
if(port<=PF){
	switch(port){
		case PA:
		SET_BIT(RCGCGPIO,0);                    //Active Clock Of PORTA
		delay_A=RCGCGPIO;                      //Delay
		GPIOLOCK_A=0x4C4F434B;                       //UNLOCK PORTA
		GPIOCR_A=0x000000FF;                        //Enable PORTA PIN
		GPIOAFSEL_A=0x00000000;                      // Disable Alternative Function Of PORTA
		GPIOPCTL_A=0x00000000;
		GPIOMSEL_A=0x00000000;
		break;
		case PB:
		SET_BIT(RCGCGPIO,1);                       //Active Clock Of PORTB
		delay_B=RCGCGPIO;                      //Delay
		GPIOLOCK_B=0x4C4F434B;                       //UNLOCK PORTB
		GPIOCR_B=0x000000FF;                        //Enable PORTB PIN
		GPIOAFSEL_B=0x00000000;                      // Disable Alternative Function Of PORTB
		GPIOPCTL_B=0x00000000;
		GPIOMSEL_B=0x00000000;
		break;
		case PC:
		SET_BIT(RCGCGPIO,2);                       //Active Clock Of PORTC
		delay_C=RCGCGPIO;                      //Delay
		GPIOLOCK_C=0x4C4F434B;                       //UNLOCK PORTC
		GPIOCR_C=0x000000FF;                        //Enable PORTC PIN
		GPIOAFSEL_C=0x00000000;                      // Disable Alternative Function Of PORTC
		GPIOPCTL_C=0x00000000;
		GPIOMSEL_C=0x00000000;
		break;
		case PD:
		SET_BIT(RCGCGPIO,3);                       //Active Clock Of PORTD
		delay_D=RCGCGPIO;                      //Delay
		GPIOLOCK_D=0x4C4F434B;                       //UNLOCK PORTD
		GPIOCR_D=0x000000FF;                        //Enable PORTD PIN
		GPIOAFSEL_D=0x00000000;                      // Disable Alternative Function Of PORTD
		GPIOPCTL_D=0x00000000;
		GPIOMSEL_D=0x00000000;
		break;
		case PE:
		SET_BIT(RCGCGPIO,4);                       //Active Clock Of PORTE
		delay_E=RCGCGPIO;                      //Delay
		GPIOLOCK_E=0x4C4F434B;                       //UNLOCK PORTE
		GPIOCR_E=0x0000003F;                        //Enable PORTE PIN
		GPIOAFSEL_E=0x00000000;                      // Disable Alternative Function Of PORTE
		GPIOPCTL_E=0x00000000;
		GPIOMSEL_E=0x00000000;
		break;
		case PF:
		SET_BIT(RCGCGPIO,5);                      //Active Clock Of PORTF
		delay_F=RCGCGPIO;                      //Delay
		GPIOLOCK_F=0x4C4F434B;                       //UNLOCK PORTF
		GPIOCR_F=0x0000001F;                        //Enable PORTF PIN
		GPIOAFSEL_F=0x00000000;                      // Disable Alternative Function Of PORTF
		GPIOPCTL_F=0x00000000;
		GPIOMSEL_F=0x00000000;
		break;

	}
}



}



void GPIO_Set_Pin_Direction(PORT_ID port ,PIN_ID pin,DIRECTION_ID direction){
if((port<=PF)&&(pin<=PIN7)){
	switch(direction){
	case OUT:
		switch(port){
		case PA:
			SET_BIT(GPIODIR_A,pin);
			break;
		case PB:
			SET_BIT(GPIODIR_B,pin);
			break;
		case PC:
			SET_BIT(GPIODIR_C,pin);
			break;
		case PD:
			SET_BIT(GPIODIR_D,pin);
			break;
		case PE:
			if(pin<=PIN5){
				SET_BIT(GPIODIR_E,pin);
			}
			break;
		case PF:
			if(pin<=PIN4){
				SET_BIT(GPIODIR_F,pin);
			}
			break;
		}
		break;
	case INFREE:
		switch(port){
		case PA:
			CLR_BIT(GPIODIR_A,pin);
			break;
		case PB:
			CLR_BIT(GPIODIR_B,pin);
			break;
		case PC:
			CLR_BIT(GPIODIR_C,pin);
			break;
		case PD:
			CLR_BIT(GPIODIR_D,pin);
			break;
		case PE:
			if(pin<=PIN5){
				CLR_BIT(GPIODIR_E,pin);
			}
			break;
		case PF:
			if(pin<=PIN4){
				CLR_BIT(GPIODIR_F,pin);
			}
			break;
		}
		break;
	case INPULLUP:
		switch(port){
		case PA:
			CLR_BIT(GPIODIR_A,pin);
			SET_BIT(GPIOPUR_A,pin);
			break;
		case PB:
			CLR_BIT(GPIODIR_B,pin);
			SET_BIT(GPIOPUR_B,pin);
			break;
		case PC:
			CLR_BIT(GPIODIR_C,pin);
			SET_BIT(GPIOPUR_C,pin);
			break;
		case PD:
			CLR_BIT(GPIODIR_D,pin);
			SET_BIT(GPIOPUR_D,pin);
			break;
		case PE:
			if(pin<=PIN5){
				CLR_BIT(GPIODIR_E,pin);
				SET_BIT(GPIOPUR_E,pin);
			}
			break;
		case PF:
			if(pin<=PIN4){
				CLR_BIT(GPIODIR_F,pin);
				SET_BIT(GPIOPUR_F,pin);
			}
			break;
		}
		break;
	case INPULLDOWN:
		switch(port){
		case PA:
			CLR_BIT(GPIODIR_A,pin);
			SET_BIT(GPIOPDR_A,pin);
			break;
		case PB:
			CLR_BIT(GPIODIR_B,pin);
			SET_BIT(GPIOPDR_B,pin);
			break;
		case PC:
			CLR_BIT(GPIODIR_C,pin);
			SET_BIT(GPIOPDR_C,pin);
			break;
		case PD:
			CLR_BIT(GPIODIR_D,pin);
			SET_BIT(GPIOPDR_D,pin);
			break;
		case PE:
			if(pin<=PIN5){
				CLR_BIT(GPIODIR_E,pin);
				SET_BIT(GPIOPDR_E,pin);
			}
			break;
		case PF:
			if(pin<=PIN4){
				CLR_BIT(GPIODIR_F,pin);
				SET_BIT(GPIOPDR_F,pin);
			}
			break;
		}
		break;




	}

}
}

void GPIO_Set_Port_Direction(PORT_ID port,DIRECTION_ID direction){
	if(port<=PF){
		switch(direction){
		case OUT:
			switch(port){
			case PA:
				SET_BIT(GPIODIR_A,0);
				SET_BIT(GPIODIR_A,1);
				SET_BIT(GPIODIR_A,2);
				SET_BIT(GPIODIR_A,3);
				SET_BIT(GPIODIR_A,4);
				SET_BIT(GPIODIR_A,5);
				SET_BIT(GPIODIR_A,6);
				SET_BIT(GPIODIR_A,7);
				break;
			case PB:
				SET_BIT(GPIODIR_B,0);
				SET_BIT(GPIODIR_B,1);
				SET_BIT(GPIODIR_B,2);
				SET_BIT(GPIODIR_B,3);
				SET_BIT(GPIODIR_B,4);
				SET_BIT(GPIODIR_B,5);
				SET_BIT(GPIODIR_B,6);
				SET_BIT(GPIODIR_B,7);
				break;
			case PC:
				SET_BIT(GPIODIR_C,0);
				SET_BIT(GPIODIR_C,1);
				SET_BIT(GPIODIR_C,2);
				SET_BIT(GPIODIR_C,3);
				SET_BIT(GPIODIR_C,4);
				SET_BIT(GPIODIR_C,5);
				SET_BIT(GPIODIR_C,6);
				SET_BIT(GPIODIR_C,7);
				break;
			case PD:
				SET_BIT(GPIODIR_D,0);
				SET_BIT(GPIODIR_D,1);
				SET_BIT(GPIODIR_D,2);
				SET_BIT(GPIODIR_D,3);
				SET_BIT(GPIODIR_D,4);
				SET_BIT(GPIODIR_D,5);
				SET_BIT(GPIODIR_D,6);
				SET_BIT(GPIODIR_D,7);
				break;
			case PE:
				SET_BIT(GPIODIR_E,0);
				SET_BIT(GPIODIR_E,1);
				SET_BIT(GPIODIR_E,2);
				SET_BIT(GPIODIR_E,3);
				SET_BIT(GPIODIR_E,4);
				SET_BIT(GPIODIR_E,5);
				break;
			case PF:
				SET_BIT(GPIODIR_F,0);
				SET_BIT(GPIODIR_F,1);
				SET_BIT(GPIODIR_F,2);
				SET_BIT(GPIODIR_F,3);
				SET_BIT(GPIODIR_F,4);
				break;

			}
		    break;
		case INFREE:
			switch(port){
			case PA:
				CLR_BIT(GPIODIR_A,0);
				CLR_BIT(GPIODIR_A,1);
				CLR_BIT(GPIODIR_A,2);
				CLR_BIT(GPIODIR_A,3);
				CLR_BIT(GPIODIR_A,4);
				CLR_BIT(GPIODIR_A,5);
				CLR_BIT(GPIODIR_A,6);
				CLR_BIT(GPIODIR_A,7);
				break;
			case PB:
				CLR_BIT(GPIODIR_B,0);
				CLR_BIT(GPIODIR_B,1);
				CLR_BIT(GPIODIR_B,2);
				CLR_BIT(GPIODIR_B,3);
				CLR_BIT(GPIODIR_B,4);
				CLR_BIT(GPIODIR_B,5);
				CLR_BIT(GPIODIR_B,6);
				CLR_BIT(GPIODIR_B,7);
				break;
			case PC:
				CLR_BIT(GPIODIR_C,0);
				CLR_BIT(GPIODIR_C,1);
				CLR_BIT(GPIODIR_C,2);
				CLR_BIT(GPIODIR_C,3);
				CLR_BIT(GPIODIR_C,4);
				CLR_BIT(GPIODIR_C,5);
				CLR_BIT(GPIODIR_C,6);
				CLR_BIT(GPIODIR_C,7);
				break;
			case PD:
				CLR_BIT(GPIODIR_D,0);
				CLR_BIT(GPIODIR_D,1);
				CLR_BIT(GPIODIR_D,2);
				CLR_BIT(GPIODIR_D,3);
				CLR_BIT(GPIODIR_D,4);
				CLR_BIT(GPIODIR_D,5);
				CLR_BIT(GPIODIR_D,6);
				CLR_BIT(GPIODIR_D,7);
				break;
			case PE:
				CLR_BIT(GPIODIR_E,0);
				CLR_BIT(GPIODIR_E,1);
				CLR_BIT(GPIODIR_E,2);
				CLR_BIT(GPIODIR_E,3);
				CLR_BIT(GPIODIR_E,4);
				CLR_BIT(GPIODIR_E,5);
				break;
			case PF:
				CLR_BIT(GPIODIR_F,0);
				CLR_BIT(GPIODIR_F,1);
				CLR_BIT(GPIODIR_F,2);
				CLR_BIT(GPIODIR_F,3);
				CLR_BIT(GPIODIR_F,4);
				break;

			}
			break;
		case INPULLDOWN:
			switch(port){
			case PA:
				CLR_BIT(GPIODIR_A,0);
				CLR_BIT(GPIODIR_A,1);
				CLR_BIT(GPIODIR_A,2);
				CLR_BIT(GPIODIR_A,3);
				CLR_BIT(GPIODIR_A,4);
				CLR_BIT(GPIODIR_A,5);
				CLR_BIT(GPIODIR_A,6);
				CLR_BIT(GPIODIR_A,7);
				SET_BIT(GPIOPDR_A,0);
				SET_BIT(GPIOPDR_A,1);
				SET_BIT(GPIOPDR_A,2);
				SET_BIT(GPIOPDR_A,3);
				SET_BIT(GPIOPDR_A,4);
				SET_BIT(GPIOPDR_A,5);
				SET_BIT(GPIOPDR_A,6);
				SET_BIT(GPIOPDR_A,7);
				break;
			case PB:
				CLR_BIT(GPIODIR_B,0);
				CLR_BIT(GPIODIR_B,1);
				CLR_BIT(GPIODIR_B,2);
				CLR_BIT(GPIODIR_B,3);
				CLR_BIT(GPIODIR_B,4);
				CLR_BIT(GPIODIR_B,5);
				CLR_BIT(GPIODIR_B,6);
				CLR_BIT(GPIODIR_B,7);
				SET_BIT(GPIOPDR_B,0);
				SET_BIT(GPIOPDR_B,1);
				SET_BIT(GPIOPDR_B,2);
				SET_BIT(GPIOPDR_B,3);
				SET_BIT(GPIOPDR_B,4);
				SET_BIT(GPIOPDR_B,5);
				SET_BIT(GPIOPDR_B,6);
				SET_BIT(GPIOPDR_B,7);
				break;
			case PC:
				CLR_BIT(GPIODIR_C,0);
				CLR_BIT(GPIODIR_C,1);
				CLR_BIT(GPIODIR_C,2);
				CLR_BIT(GPIODIR_C,3);
				CLR_BIT(GPIODIR_C,4);
				CLR_BIT(GPIODIR_C,5);
				CLR_BIT(GPIODIR_C,6);
				CLR_BIT(GPIODIR_C,7);
				SET_BIT(GPIOPDR_C,0);
				SET_BIT(GPIOPDR_C,1);
				SET_BIT(GPIOPDR_C,2);
				SET_BIT(GPIOPDR_C,3);
				SET_BIT(GPIOPDR_C,4);
				SET_BIT(GPIOPDR_C,5);
				SET_BIT(GPIOPDR_C,6);
				SET_BIT(GPIOPDR_C,7);
				break;
			case PD:
				CLR_BIT(GPIODIR_D,0);
				CLR_BIT(GPIODIR_D,1);
				CLR_BIT(GPIODIR_D,2);
				CLR_BIT(GPIODIR_D,3);
				CLR_BIT(GPIODIR_D,4);
				CLR_BIT(GPIODIR_D,5);
				CLR_BIT(GPIODIR_D,6);
				CLR_BIT(GPIODIR_D,7);
				SET_BIT(GPIOPDR_D,0);
				SET_BIT(GPIOPDR_D,1);
				SET_BIT(GPIOPDR_D,2);
				SET_BIT(GPIOPDR_D,3);
				SET_BIT(GPIOPDR_D,4);
				SET_BIT(GPIOPDR_D,5);
				SET_BIT(GPIOPDR_D,6);
				SET_BIT(GPIOPDR_D,7);
				break;
			case PE:
				CLR_BIT(GPIODIR_E,0);
				CLR_BIT(GPIODIR_E,1);
				CLR_BIT(GPIODIR_E,2);
				CLR_BIT(GPIODIR_E,3);
				CLR_BIT(GPIODIR_E,4);
				CLR_BIT(GPIODIR_E,5);
				SET_BIT(GPIOPDR_E,0);
				SET_BIT(GPIOPDR_E,1);
				SET_BIT(GPIOPDR_E,2);
				SET_BIT(GPIOPDR_E,3);
				SET_BIT(GPIOPDR_E,4);
				SET_BIT(GPIOPDR_E,5);
				break;
			case PF:
				CLR_BIT(GPIODIR_F,0);
				CLR_BIT(GPIODIR_F,1);
				CLR_BIT(GPIODIR_F,2);
				CLR_BIT(GPIODIR_F,3);
				CLR_BIT(GPIODIR_F,4);
				SET_BIT(GPIOPDR_F,0);
				SET_BIT(GPIOPDR_F,1);
				SET_BIT(GPIOPDR_F,2);
				SET_BIT(GPIOPDR_F,3);
				SET_BIT(GPIOPDR_F,4);
				break;

			}
			break;
		case INPULLUP:
			switch(port){
			case PA:
				CLR_BIT(GPIODIR_A,0);
				CLR_BIT(GPIODIR_A,1);
				CLR_BIT(GPIODIR_A,2);
				CLR_BIT(GPIODIR_A,3);
				CLR_BIT(GPIODIR_A,4);
				CLR_BIT(GPIODIR_A,5);
				CLR_BIT(GPIODIR_A,6);
				CLR_BIT(GPIODIR_A,7);
				SET_BIT(GPIOPUR_A,0);
				SET_BIT(GPIOPUR_A,1);
				SET_BIT(GPIOPUR_A,2);
				SET_BIT(GPIOPUR_A,3);
				SET_BIT(GPIOPUR_A,4);
				SET_BIT(GPIOPUR_A,5);
				SET_BIT(GPIOPUR_A,6);
				SET_BIT(GPIOPUR_A,7);
				break;
			case PB:
				CLR_BIT(GPIODIR_B,0);
				CLR_BIT(GPIODIR_B,1);
				CLR_BIT(GPIODIR_B,2);
				CLR_BIT(GPIODIR_B,3);
				CLR_BIT(GPIODIR_B,4);
				CLR_BIT(GPIODIR_B,5);
				CLR_BIT(GPIODIR_B,6);
				CLR_BIT(GPIODIR_B,7);
				SET_BIT(GPIOPUR_B,0);
				SET_BIT(GPIOPUR_B,1);
				SET_BIT(GPIOPUR_B,2);
				SET_BIT(GPIOPUR_B,3);
				SET_BIT(GPIOPUR_B,4);
				SET_BIT(GPIOPUR_B,5);
				SET_BIT(GPIOPUR_B,6);
				SET_BIT(GPIOPUR_B,7);
				break;
			case PC:
				CLR_BIT(GPIODIR_C,0);
				CLR_BIT(GPIODIR_C,1);
				CLR_BIT(GPIODIR_C,2);
				CLR_BIT(GPIODIR_C,3);
				CLR_BIT(GPIODIR_C,4);
				CLR_BIT(GPIODIR_C,5);
				CLR_BIT(GPIODIR_C,6);
				CLR_BIT(GPIODIR_C,7);
				SET_BIT(GPIOPUR_C,0);
				SET_BIT(GPIOPUR_C,1);
				SET_BIT(GPIOPUR_C,2);
				SET_BIT(GPIOPUR_C,3);
				SET_BIT(GPIOPUR_C,4);
				SET_BIT(GPIOPUR_C,5);
				SET_BIT(GPIOPUR_C,6);
				SET_BIT(GPIOPUR_C,7);
				break;
			case PD:
				CLR_BIT(GPIODIR_D,0);
				CLR_BIT(GPIODIR_D,1);
				CLR_BIT(GPIODIR_D,2);
				CLR_BIT(GPIODIR_D,3);
				CLR_BIT(GPIODIR_D,4);
				CLR_BIT(GPIODIR_D,5);
				CLR_BIT(GPIODIR_D,6);
				CLR_BIT(GPIODIR_D,7);
				SET_BIT(GPIOPUR_D,0);
				SET_BIT(GPIOPUR_D,1);
				SET_BIT(GPIOPUR_D,2);
				SET_BIT(GPIOPUR_D,3);
				SET_BIT(GPIOPUR_D,4);
				SET_BIT(GPIOPUR_D,5);
				SET_BIT(GPIOPUR_D,6);
				SET_BIT(GPIOPUR_D,7);
				break;
			case PE:
				CLR_BIT(GPIODIR_E,0);
				CLR_BIT(GPIODIR_E,1);
				CLR_BIT(GPIODIR_E,2);
				CLR_BIT(GPIODIR_E,3);
				CLR_BIT(GPIODIR_E,4);
				CLR_BIT(GPIODIR_E,5);
				SET_BIT(GPIOPUR_E,0);
				SET_BIT(GPIOPUR_E,1);
				SET_BIT(GPIOPUR_E,2);
				SET_BIT(GPIOPUR_E,3);
				SET_BIT(GPIOPUR_E,4);
				SET_BIT(GPIOPUR_E,5);
				break;
			case PF:
				CLR_BIT(GPIODIR_F,0);
				CLR_BIT(GPIODIR_F,1);
				CLR_BIT(GPIODIR_F,2);
				CLR_BIT(GPIODIR_F,3);
				CLR_BIT(GPIODIR_F,4);
				SET_BIT(GPIOPUR_F,0);
				SET_BIT(GPIOPUR_F,1);
				SET_BIT(GPIOPUR_F,2);
				SET_BIT(GPIOPUR_F,3);
				SET_BIT(GPIOPUR_F,4);
				break;

			}
			break;
		}
	}
}





void GPIO_Write_Pin(PORT_ID port,PIN_ID pin,VOLTAGE_ID value){
	if((port<=PF)&&(pin<=PIN7)){
		if(value==LOWV){
			switch(port){
			case PA:
				CLR_BIT(GPIODATA_A,pin);
				break;
			case PB:
				CLR_BIT(GPIODATA_B,pin);
				break;
			case PC:
				CLR_BIT(GPIODATA_C,pin);
				break;
			case PD:
				CLR_BIT(GPIODATA_D,pin);
			    break;
			case PE:
				if(pin<=PIN5){
				CLR_BIT(GPIODATA_E,pin);
				}
				break;
			case PF:
				if(pin<=PIN4){
				CLR_BIT(GPIODATA_F,pin);
				}
				break;

			}
		}else if(value==HIGHV){
			switch(port){
			case PA:
				SET_BIT(GPIODATA_A,pin);
				break;
			case PB:
				SET_BIT(GPIODATA_B,pin);
				break;
			case PC:
				SET_BIT(GPIODATA_C,pin);
				break;
			case PD:
				SET_BIT(GPIODATA_D,pin);
			    break;
			case PE:
				if(pin<=PIN5){
				SET_BIT(GPIODATA_E,pin);
				}
				break;
			case PF:
				if(pin<=PIN4){
				SET_BIT(GPIODATA_F,pin);
				}
				break;

			}
		}

	}
}





void GPIO_Write_Port(PORT_ID port,u8 value){
	if(port<=PF){
		switch(port){
		case PA:
			GPIODATA_A=value;
			break;
		case PB:
			GPIODATA_B=value;
			break;
		case PC:
			GPIODATA_C=value;
			break;
		case PD:
			GPIODATA_D=value;
			break;
		case PE:
			GPIODATA_E=value;
			break;
		case PF:
			GPIODATA_F=value;
			break;

		}
	}
}

u8* GPIO_Read_Pin(PORT_ID port,PIN_ID pin,u8* value){
	u8 *data;
	if((port<=PF)&&(pin<=PIN7)){
		switch(port){
		case PA:
			*value=GET_BIT(GPIODATA_A,pin);
			*data=*value;
			break;
		case PB:
			*value=GET_BIT(GPIODATA_B,pin);
			*data=*value;
			break;
		case PC:
			*value=GET_BIT(GPIODATA_C,pin);
			*data=*value;
			break;
		case PD:
			*value=GET_BIT(GPIODATA_D,pin);
			*data=*value;
			break;
		case PE:
			if(pin<=PIN5){
				*value=GET_BIT(GPIODATA_E,pin);
				*data=*value;
			}
			break;
		case PF:
			if(pin<=PIN4){
				*value=GET_BIT(GPIODATA_F,pin);
				*data=*value;
			}
			break;


		}

	}
	return *data;
}


u8* GPIO_Read_Port(PORT_ID port,u8* value){
    u8* data;
    if(port<=PF){
    	switch(port){
    	case PA:
    		*value=GPIODATA_A;
    		*data=*value;
    		break;
    	case PB:
    		*value=GPIODATA_B;
    		*data=*value;
    		break;
    	case PC:
    		*value=GPIODATA_C;
    		*data=*value;
    		break;
    	case PD:
    		*value=GPIODATA_D;
    		*data=*value;
    		break;
    	case PE:
    		*value=GPIODATA_E;
    		*data=*value;
    		break;
    	case PF:
    		*value=GPIODATA_F;
    		*data=*value;
    		break;

    	}
    }
    return *data;

}
