#include "beginner_tutorials/AddTwoInts.h"
#include "ros/ros.h"
#include "ros/service_client.h"

int main(int argc, char **argv) {
  if (argc != 3) {
    ROS_INFO("the number of argument is wrong, please inpute two arguments!");
    return 1;
  }
  ros::init(argc, argv, "AddInts_Client");

  ros::NodeHandle nh;

  ros::ServiceClient client =
      nh.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");

  beginner_tutorials::AddTwoInts srv;
  // 自定义参数，atoll将字符串转换成long int
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  // 等待服务器启动
  client.waitForExistence();

  if (client.call(srv)) {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  } else {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
