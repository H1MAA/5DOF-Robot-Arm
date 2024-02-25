# How to Setup Repository
Copy Paste the following into your terminal
```
mkdir catkin_ws && cd catkin_ws
mkdir src && cd src
git clone https://github.com/H1MAA/5DOF-Robot-Arm.git .
cd ..
catkin build
echo 'source ~/catkin_ws/devel/setup.bash' >> ~/.bashrc
```
