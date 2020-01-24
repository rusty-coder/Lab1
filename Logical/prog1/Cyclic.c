
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	if(enable)
	{
		count += 10;
		if(count<=5000)
		{
			speed=0;
		}
		else
		{
			speed=6;
			if(count>=10000)
			{
				count=0;
			}
		}
	}
	fb_controller.e=speed-fb_motor.w;
	fb_motor2.u=speed*fb_motor2.ke;
	
	FB_Regulator(&fb_controller);
	
	fb_motor.u=fb_controller.u*fb_motor.ke;
	
	FB_Motor(&fb_motor);
	FB_Motor(&fb_motor2);
}
