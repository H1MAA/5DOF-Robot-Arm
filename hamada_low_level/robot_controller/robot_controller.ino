#include <ros.h>
#include <std_msgs/Int16MultiArray.h>
#include <Timer.h>
#include <Servo.h>

#define period 1

Timer updater;

Servo base;
Servo link1;
Servo link2;
Servo link3;
Servo end_eff;

int servos[] = { 50, 150, 0, 60, 0 };

ros::NodeHandle nh;

// std_msgs::String debug_msg;
// ros::Publisher debug("debug", &debug_msg);


void servos_cb(const std_msgs::Int16MultiArray &servo_cb) {
  for (int i = 0; i < 5; i++) {
    servos[i] = servo_cb.data[i];
  }
}

ros::Subscriber<std_msgs::Int16MultiArray> servo_subscriber("servos", &servos_cb);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  nh.initNode();
  nh.subscribe(servo_subscriber);
  // nh.advertise(debug);

  base.attach(3);
  link1.attach(5);
  link2.attach(6);
  link3.attach(9);
  end_eff.attach(10);

  // updater.every(period, servoRoutine);
}

void loop() {
  // put your main code here, to run repeatedly:
  // updater.update();
  // String msg = "The output of the Servos are"
  base.write(servos[0]);
  link1.write(servos[1]);
  link2.write(servos[2]);
  link3.write(servos[3]);

  nh.spinOnce();
}

void servoRoutine() {

  //   end_eff.write(servos[4])
}
