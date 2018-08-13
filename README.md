# imgs_to_rosvideo

This package reads images from a folder that are named numerically in order with the same name width; e.g. 00001.jpg, 00002.jpg, etc;
and publishes them in ROS. The images must be named sequentially, but you can omit numbers.
For example, in the folder path *home/user_name/Pictures/* I could have the following images

- 00001.jpg
- 00002.jpg
- 00004.jpg

These images will be processed in order, skipping image 00003.jpg since it doens't exit. 
Also note that all have a name width of 5 characters (not including '.jpg'). 

## Parameters

You can adjust the parameters located in *para/default.yaml* to accomadate your own needs. 

| Parameter Name | Description                                                                                                                                           | Default Value             |
|----------------|-------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------|
| img_type       | The image type: jpg, png, etc.                                                                                                                        | jpg                       |
| img_path       | The path to the folder containing the images.                                                                                                         | /home/user_name/Pictures/ |
| begin_img      | The first image to be processed.                                                                                                                      | 0                         |
| end_img        | The last image to be processed.                                                                                                                       | 100                       |
| name_width     | The number of characters that compose the image name not including '.img_type'.  Ex. The image with the name 000001.jpg would have a name_width of 6. | 12                        |
| fps            | The rate at which the images are being published.                                                                                                     | 15                        |
| repeate        | Indicates if you want to repeatedly publish all the images.                                                                                           | false                     |
| resize         | Indicates if you want to resize the images.                                                                                                           | false                     |
| rows,cols      | The dimensions of the resized image.                                                                                                                  | (480,640)                 |
