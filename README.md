
## C++ ROS 2 node that sends some trajectory for a TiAGo arm on simulation

## Writing the c++ node

I Have include the c++ script. After building the below repository, put this is the this c++ file in the ~/tiago_simulation/tiago_gazebo/scripts

Modify the CmakeLists and package xml accordingly 

![Watch the demo](https://img.youtube.com/vi/1rGfhZ1y_-Q/0.jpg)](https://www.youtube.com/watch?v=1rGfhZ1y_-Q)

▶️ CLick above to watch the video on youtube


### Setting up the workspace

Create a workspace and clone all repositories:

```console
mkdir -p ~/tiago_public_ws/src
cd ~/tiago_public_ws
vcs import --input https://raw.githubusercontent.com/pal-robotics/tiago_tutorials/humble-devel/tiago_public.repos src
```

Install dependencies using rosdep

```console
sudo rosdep init
rosdep update
rosdep install --from-paths src -y --ignore-src
```

Source the environment and build

```console
source /opt/ros/humble/setup.bash
colcon build --symlink-install
```

Finally, before running any application you have to source the workspace

```console
source ~/tiago_public_ws/install/setup.bash
```

Also you can add it to your .bashrc


## Simulation

### Standalone

Launch gazebo simulation:

```console
ros2 launch tiago_gazebo tiago_gazebo.launch.py is_public_sim:=True
Now run the c++ node

```

