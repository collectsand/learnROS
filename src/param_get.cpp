#include <string>

#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/param.h"

int main(int argc, char* argv[]) {
	ros::init(argc, argv, "param_get");

	ros::NodeHandle nh;
	// 有好几种获取键的方法，详见赵虚左的教程文档
	std::string p;
	if (nh.getParam("param_name", p)) {
		ROS_INFO("param_name is %s", p.c_str());
	} else {
		ROS_INFO("something goes wrong");
	}

	double pd;
	if (ros ::param::getCached("param_num2", pd)) {
		ROS_INFO("value is %f", pd);
	} else {
		ROS_INFO("can't get param_num2");
	}

	return 0;
}