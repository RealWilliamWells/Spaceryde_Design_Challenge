#include <ros/ros.h>
#include <accelerometer_simulator/accelerometer_measurement.h>

#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "accelerometer_simulator_node");
    ros::NodeHandle n;

    std::string publisher_topic = "accelerometer_sensor";

    ros::Publisher accelerometer_publisher = n.advertise<accelerometer_simulator::accelerometer_measurement>(publisher_topic, 1000);

    // Update at rate of 1Hz
    ros::Rate loop_rate(1);

    accelerometer_simulator::accelerometer_measurement msg;

    while (ros::ok()) {
        float coordinateX = 10;
        float coordinateZ = 20;

        // Gaussian noise generation
        int standardDeviation = 60;
        coordinateX += rand() % standardDeviation + 1;
        coordinateZ += rand() % standardDeviation + 1;

        msg.x = coordinateX;
        msg.z = coordinateZ;

//        ROS_INFO("%s", msg.x.c_str());

        accelerometer_publisher.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}



