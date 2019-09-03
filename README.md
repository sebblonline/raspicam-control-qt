# RaspiCam control GUI

Simple client GUI to view live images from a Raspberry Pi camera. It works together with the [raspicam-daemon]() server app.

## Prerequisites

* CMake version 3.0 or later
* `Qt5`. Tested and developed with version `5.12.3` but should work with every `5.x` version.

## Build & run

I use Qt installed with the official online installer. If you use a different approach, e.g. with a self compile Qt, the following steps may be insufficient. Manually setting the Qt directory could be necessary.

### Using command line

```
mkdir build
cd build
cmake ..
make
./raspicam-control-qt
```

### Using an IDE

I prefer Qt Creator which I used for development and works out of the box. But the project should work with any other IDE that supports CMake.

## Related projects

*TODO*
[raspicam-daemon]()

## Future plans

* Add interface to receive configuration settings
* Build as an Android app

## Contribution

*TODO*


## Authors

* **Sebastian Reichert** - *Initial work* - [sebblonline](https://github.com/sebblonline)


## License

*TODO*
