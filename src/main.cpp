#include "main.h"



void UI_Touch() {
	 pros::screen_touch_status_s_t status = pros::screen::touch_status();
	 pros::screen::set_pen(COLOR_GREEN);
	 Touch_Checker(status.x, status.y);
 }
void initialize() {
	
	pros::delay(300); 
	Start_UI();
	drivetrain.Initialize();
	pros::screen::touch_callback(UI_Touch, TOUCH_PRESSED);

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
	//Auto_Programs[1].Current_Auto;
	//Run_Auto();
	Auton_7();
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

void GUI_Updater(void* param)
{
	//Start_GUI();
}
//extern pros::Task RPM_Task;
void opcontrol() {
	Catapult.set_brake_modes(MOTOR_BRAKE_COAST);
	//pros::Task  GUI_Update(heading_tracker);
	drivetrain.Change_Brake_Type(Drivetrain::COAST);
	while (true) {
		
		Marco_Skills();
		drivetrain.Driver_Control();
		setCatapultMotors();
		Driver_Intake();
		MutiShootCataControl(48 , 150  ,pros::E_CONTROLLER_DIGITAL_UP);
		wings.Control();
		hang.Control();
		back_left_wing.Control();
		back_right_wing.Control();
		pros::delay(20);

	}
}
