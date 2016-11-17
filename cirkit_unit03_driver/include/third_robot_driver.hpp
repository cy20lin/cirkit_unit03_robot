/******************************************************
 * This is CIR-KIT 3rd robot control driver.
 * Author : Arita Yuta(Kyutech)
 ******************************************************/

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>		// cmd_vel
#include <tf/transform_broadcaster.h>

#include <string>

namespace cirkit
{
  class ThirdRobotInterface; // forward declaration

  class ThirdRobotDriver
  {
  public:
    ThirdRobotDriver(ros::NodeHandle nh);
    ~ThirdRobotDriver();
    void run();
  private:
    // Callback function
    void cmdVelReceived(const geometry_msgs::Twist::ConstPtr& cmd_vel);

    ros::NodeHandle nh_;
    ros::Rate rate_;
    // ROS topic trader
    ros::Publisher odom_pub_;
    ros::Publisher steer_pub_;
    ros::Subscriber cmd_vel_sub_;
    // self member
    tf::TransformBroadcaster odom_broadcaster_;
    std::string imcs01_port_;
    ros::Time current_time_, last_time_;
    boost::mutex access_mutex_;
    geometry_msgs::Twist steer_dir_;
    // third robot interface object
    cirkit::ThirdRobotInterface *thirdrobot_;
  };
}
