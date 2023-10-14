#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void UI_Touch() {
	 pros::screen_touch_status_s_t status = pros::screen::touch_status();
	 pros::screen::set_pen(COLOR_GREEN);
	 Touch_Checker(status.x, status.y);
 }
void initialize() {
	pros::delay(300); 
	Start_UI();
	pros::screen::touch_callback(UI_Touch, TOUCH_PRESSED);
	Auto_IMU.reset();
	rotation_sensor.reset_position();
	rotation_sensor.reset();
	rotation_sensor.set_data_rate(5);
	rotation_sensor.set_position(0);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

	//AutoDrive(24,100);
	Auto_Turn(90,100);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void my_task_fn(void* param) {
     while(true){
      Driver_AutoCatapult();
	  pros::delay(20);
     }
 }
void opcontrol() {
	Change_DT_Brake(1);
	Catapult.set_brake_mode(MOTOR_BRAKE_COAST);
	pros::Task  my_task(my_task_fn);
	
	while (true) {
		 
		Basic_Control();
		setCatapultMotors();
		Driver_Intake();
		//Driver_AutoCatapult();
		Wings_Driver_Control();
		Hang_Driver_Control();
		Intake_Lift_Driver_Control();
        pros::delay(20);
	}
}
