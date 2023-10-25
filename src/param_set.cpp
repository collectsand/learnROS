#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/param.h"
#include "ros/ros.h"

int main(int argc, char *argv[]) {
	ros::init(argc, argv, "param_get");

	ros::NodeHandle nh;
	// 设置参数
	nh.setParam("param_name", "eman");
	nh.setParam("param_num", 3.1415);

	ros::param::set("param_name2", "marap");
	ros::param::set("param_num2", 123123);
	// 修改参数
	nh.setParam("param_num", 0.2);
	return 0;
}