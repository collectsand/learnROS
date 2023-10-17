#include "beginner_tutorials/AddTwoInts.h"
#include "beginner_tutorials/AddTwoIntsRequest.h"
#include "beginner_tutorials/AddTwoIntsResponse.h"
#include "ros/init.h"
#include "ros/ros.h"
#include "ros/service_server.h"

bool server_callback(beginner_tutorials::AddTwoIntsRequest &req,
                     beginner_tutorials::AddTwoIntsResponse &res) {
  if (req.a > 0 && req.b > 0) {
    res.sum = req.a + req.b;
    ROS_INFO("a=%ld, b=%ld, sum=%ld", req.a, req.b, res.sum);
    return true;
  } else {
    ROS_INFO("a,b can't be negative number");
    return false;
  }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "AddInts_Server");

  ros::NodeHandle nh;

  ros::ServiceServer server =
      nh.advertiseService("add_two_ints", server_callback);

  ROS_INFO("Server has started");

  ros::spin();

  return 0;
}
