# ros_params_demo

[rosparam](http://wiki.ros.org/rosparam) contains the rosparam command-line tool for getting and setting ROS Parameters on the Parameter Server using YAML-encoded files. We can also use a series of functions in a ros package to set or get parameters. There are two possible ways to use it:

* in roslaunch files
* in source files

These package will demonstrate how to do this.

## YAML Format
YAML is a lightweight markup language that supports all parameter types. For more information on YAML, you can see [the YAML 1.2 spec](http://yaml.org/spec/1.2/spec.html).

## In source files
This package shows some examples to invoke ROS API functions to set and get parameters following [the official guide](http://wiki.ros.org/roscpp/Overview/Parameter%20Server) .

## In roslaunch files
Sometimes you would like to separate parameters and codes for better organization. Write your parameter lists in .yaml files and invoke them by roslaunch is a powerful approach. Just try the roslaunch file contained in the forder *launch* by the following command in your workspace:
```bash
roslaunch ros_params_demo ros_params_demo_node.launch
```
