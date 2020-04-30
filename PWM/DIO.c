/*
 * DIO.c
 *
 *  Created on: Aug 30, 2019
 *      Author: Ahmed Magdy
 */
#include "stdtypes.h"
#include "Util.h"
#include "memmap.h"

#include "DIO.h"

read mystruct;
DIOStatus_t DIO_SetPinDirection (DIOPortID_t port ,DIOPinID_t pin,DIODirection_t dir)
{
	if((pin<=PIN7)&&(port<=PD))
	{
		switch (port)
		{
		case PA :
			switch (dir)
			{
			case OUT :
				SET_BIT(DDRA,pin);
				break;
			case INFREE :
				CLR_BIT(DDRA,pin);
				break;
			case INPULLUP :
				CLR_BIT(DDRA,pin);
				SET_BIT(PORTA,pin);
				break;

			}
			break;
			case PB :
			     switch (dir)
			    {
			     	case OUT :
			    	SET_BIT(DDRB,pin);
			    	break;
			     	case INFREE :
			        CLR_BIT(DDRB,pin);
			        break;
			     	case INPULLUP :
			        CLR_BIT(DDRB,pin);
			        SET_BIT(PORTB,pin);
			        break;

			   }
			   break;
			case PC :
				switch (dir)
			{
				case OUT :
				SET_BIT(DDRC,pin);
				break;
				case INFREE :
				CLR_BIT(DDRC,pin);
				break;
				case INPULLUP :
			    CLR_BIT(DDRC,pin);
			    SET_BIT(PORTC,pin);
			    break;

			}
		    break;
			case PD :
				switch (dir)
			{
				case OUT :
				SET_BIT(DDRD,pin);
				break;
				case INFREE :
				CLR_BIT(DDRD,pin);
				break;
				case INPULLUP :
				CLR_BIT(DDRD,pin);
				SET_BIT(PORTD,pin);
				break;

		   }
		   break;
	}
	return OK;
	}
	else
	{
		return NOK;
	}
}
DIOStatus_t DIO_SetPortDirection (DIOPortID_t port,u8 direction)
{

	if (port<=PD)
	{
		switch (port)
		{
		case PA :
			DDRA=direction;
			break;
		case PB :
			DDRB=direction;
			break;
		case PC :
			DDRC=direction;
			break;
		case PD :
		    DDRD=direction;
		    break;
		}
	return OK;
	}
	else
	{
		return NOK;
	}



}
void DIO_WritePin(DIOPortID_t port,DIOPinID_t pin,u8 value)
{
	if((pin<=PIN7)&&(port<=PD))
	{
		switch (port)
			{
			case PA :
				if(HIGHV==value)
				{
					SET_BIT(PORTA,pin);
				}
				else
				{
					CLR_BIT(PORTA,pin);
				}
				break;
			 case PB:
				 if(HIGHV==value)
				{
				SET_BIT(PORTB,pin);
				}
				else
				{
				CLR_BIT(PORTB,pin);
				}
				break;
			 case PC:
			 	 if(HIGHV==value)
			 	 {
			 	 SET_BIT(PORTC,pin);
			 	 }
			 	 else
			 	 {
			 	CLR_BIT(PORTC,pin);
			 	 }
			 	break;
			 case PD:
			     if(HIGHV==value)
			 	{
			 	SET_BIT(PORTD,pin);
			 	}
			 	else
			 	{
			 	CLR_BIT(PORTD,pin);
			 	}
			 	break;
			    }

		}
	else
	{

	}
}
void DIO_WritePort(DIOPortID_t port,u8 value)
{

	if (port<=PD)
	{
		switch (port)
		{
		case PA :
			PORTA=value;
			break;
		case PB :
			PORTB=value;
			break;
		case PC :
			PORTC=value;
			break;
		case PD :
		    PORTD=value;
		    break;
		}
	}
}
read DIO_ReadPin(DIOPortID_t port,DIOPinID_t pin)
{

	if((pin<=PIN7)&&(port<=PD))
	{
		switch (port)
					{
					case PA :
						mystruct.y=GET_BIT(PINA,pin);

						break;
					 case PB:
						 mystruct.y=GET_BIT(PINB,pin);

						break;
					 case PC:
						 mystruct.y=GET_BIT(PINC,pin);

					 	break;
					 case PD:
						 mystruct.y=GET_BIT(PIND,pin);
					 	break;
					    }
		mystruct.status=OK;
		return mystruct;
	}

	else {
		mystruct.status=NOK;
		return mystruct;
	}
}
u8 DIO_ReadPort(DIOPortID_t port)
{
	u8 value=0;
	if (port<=PD)
		{
			switch (port)
			{
			case PA :
				value=PINA;
				break;
			case PB :
				value=PINB;
				break;
			case PC :
				value=PINC;
				break;
			case PD :
				value=PIND;
			    break;
			}

		}
	return value;
}
void DIO_TogglePin(DIOPortID_t port,DIOPinID_t pin)
{
	switch(port)
	{
	case PA :
			TOG_BIT(PORTA,pin);
			break;
	case PB :
			TOG_BIT(PORTB,pin);
			break;
	case PC :
			TOG_BIT(PORTC,pin);
			break;
	case PD :
			TOG_BIT(PORTD,pin);
			break;

	}
}

