# Project documentation - Hough transform of an image

## Inspiration
- [https://stackoverflow.com/questions/9592818/how-to-implement-the-hough-transform](SO)
- [https://rosettacode.org/wiki/Hough_transform]()
- [https://www.uio.no/studier/emner/matnat/ifi/INF4300/h09/undervisningsmateriale/hough09.pdf]()
- [https://stackoverflow.com/questions/51886950/longest-line-detection-using-hough-line-transform/52023637]()

If you want the accuracy of angles to be 1 degree, you need 180 columns. For ro, the maximum distance possible is the diagonal length of the image.
`int maxTheta = 180;
int houghHeight = (int)( Math.Sqrt( 2 ) * Math.Max( imgWidth, imgHeight ) ) / 2;
int doubleHoughHeight = houghHeight * 2;`

## Algorithm


http://homepages.inf.ed.ac.uk/rbf/HIPR2/hough.htm <br>
The Hough transform is a technique which can be used to isolate features of a particular shape within an image. Because it requires that the desired features be specified in some parametric form, the classical Hough transform is most commonly used for the detection of regular curves such as lines, circles, ellipses, etc. <br>
A convenient equation for describing a set of lines uses parametric or normal notion:
> *xcos(theta); + ysin(theta); = r*

where r is the length of a normal from the origin to this line and theta; is the orientation of r with respect to the X-axis.<br>
The transform is implemented by quantizing the Hough parameter space into finite intervals or accumulator cells.

#### Threads
The image is represented as a matrix. So, when we have to parse the image on the width and height, basically we parse a matrix on rows and columns. Instead of having 2 *for* loops (for row and column), we create a task for parsing columns, and an executor service that takes the tasks for every row.
```java
ExecutorService executor = Executors.newFixedThreadPool(Main.numberOfThreads);
    for (int x = 0; x < image.getWidth(); x++) {
        HoughTask task = new HoughTask(x, image, this);
        executor.submit(task);
    }
executor.shutdown();
executor.awaitTermination(50, TimeUnit.SECONDS); 
```

## Performance measurements
THREADS

| Threads       | 5             | 8             | 10            |
| ------------- | ------------- | ------------- | ------------- | 
| line   | 101           | 104           | 98           |
| lines  | 107           | 101           | 104           |
| box    | 101           | 102           | 117           |
| test   | 101           | 101           | 97           |     



