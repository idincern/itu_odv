//Note:
//fr:(front-right)
//fl:(front-left)
//rr:(rear-right)
//rl:(rear-left)

#include <ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float32.h>
#include <itu_odv_navigation/motorPWMs.h> //int16[] custom message type is used for sending PWM values
#include <std_msgs/Int16MultiArray.h>

//init the nodehandle
ros::NodeHandle  nh;

//Arduino digital pins
int fr_motor = 2;
int fl_motor = 3;
int rr_motor = 5;
int rl_motor = 6;

//Arduino analog pins
int fr_motor_fb_pin=A0;
int fl_motor_fb_pin=A1;
int rr_motor_fb_pin=A2;
int rl_motor_fb_pin=A3;

//Arduino digital enable pin
int enable_motors = 4;

//init variables
double fr_motor_vel = 0;
double fl_motor_vel = 0;
double rr_motor_vel = 0;
double rl_motor_vel = 0;

double fr_motor_fb = 0;
double fl_motor_fb = 0;
double rr_motor_fb = 0;
double rl_motor_fb = 0;

int fb_array[4]={0,0,0,0};

//init the publisher
std_msgs::Int16MultiArray motor_fb;
ros::Publisher motor_fb_pub("/motor_vel_fb", &motor_fb);

void inv_kinematics_cb(const itu_odv_navigation::motorPWMs& pwms)
{
  //Sending PWM values to the motor controller
  fr_motor_vel = pwms.data[0];
  analogWrite(fr_motor, fr_motor_vel);
  
  fl_motor_vel = pwms.data[1];
  analogWrite(fl_motor, fl_motor_vel);
  
  rr_motor_vel = pwms.data[2];
  analogWrite(rr_motor, rr_motor_vel);
  
  rl_motor_vel = pwms.data[3];
  analogWrite(rl_motor, rl_motor_vel);

  //Getting analog voltage fbs from the motor controllers
  //[values between (0,4) mapped into (-2,2) and multiplied by 1000-int-(this later divided at ROS)]
  fr_motor_fb = analogRead(fr_motor_fb_pin); //rpm value fb from motor controller
  fb_array[0] = int(((5. / 1023.) * fr_motor_fb - 2.0)*1000);

  fl_motor_fb = analogRead(fl_motor_fb_pin); //rpm value fb from motor controller
  fb_array[1] = int(((5. / 1023.) * fl_motor_fb - 2.0)*1000);

  rr_motor_fb = analogRead(rr_motor_fb_pin); //rpm value fb from motor controller
  fb_array[2] = int(((5. / 1023.) * rr_motor_fb - 2.0)*1000);

  rl_motor_fb = analogRead(rl_motor_fb_pin); //rpm value fb from motor controller
  fb_array[3] = int(((5. / 1023.) * rl_motor_fb - 2.0)*1000);

  motor_fb.data=fb_array;
  motor_fb.data_length=4;
  
  motor_fb_pub.publish(&motor_fb);
}
ros::Subscriber<itu_odv_navigation::motorPWMs> req_motor_pwm("/pwm_values", &inv_kinematics_cb );

void setup() {
  nh.initNode();

  nh.subscribe(req_motor_pwm);
  nh.advertise(motor_fb_pub);

  pinMode(fr_motor, OUTPUT);
  pinMode(fl_motor, OUTPUT);
  pinMode(rr_motor, OUTPUT);
  pinMode(rl_motor, OUTPUT);

  pinMode(fr_motor_fb_pin, INPUT);
  pinMode(fl_motor_fb_pin, INPUT);
  pinMode(rr_motor_fb_pin, INPUT);
  pinMode(rl_motor_fb_pin, INPUT);

  pinMode(enable_motors, OUTPUT);
}

void loop() {
  nh.spinOnce();
  digitalWrite(enable_motors, HIGH);
  delay(10);
}
