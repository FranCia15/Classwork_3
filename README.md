# Classwork_3
Create a new ROS package containing two nodes. The goal is to publish a sinusoidal signal. The period and the amplitude must be taken in input as parameters. This signal must be published using a custom message containing the following fields:
-	Sinusoid amplitude
-	Sinusoid period
-	Sinusoid value (the time varying signal)

This data is read by another ROS node (subscribing to the sinusoidal published data). The sinusoidal signal is used IN A SEPARATE THREAD DEFINED AS CLASS FUNCTION and filtered with a low-pass filter. The new and filtered sinusoidal signal must be published on the ROS network using another (standard data) topic.
![Immagine 2023-04-19 204134](https://user-images.githubusercontent.com/124872841/233186793-4a307d07-73a2-4da6-a0ff-3d853ae54f4b.jpg)
