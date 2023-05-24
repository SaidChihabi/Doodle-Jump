# Doodle Jump in C++ with SFML

This project is a simple implementation of the Doodle Jump game. It is created using the SFML library in C++.

## Dependencies

The project uses the following dependencies:

- CMake for building the project.
- SFML, the Simple and Fast Multimedia Library. It provides a simple interface to the various components of your PC, to ease the development of games and multimedia applications.

## Building and Running

The project uses CMake, so you can build it with the following commands:

```sh
mkdir build
cd build
cmake ..
make
```

After that, you can run the game with:
```
./doodle-jump
```
## Continuous Integration

The project uses GitHub Actions for continuous integration. Every push or pull request triggers a build and checks if the code compiles successfully. You can check the [`.github/workflows/main.yaml`](.github/workflows/main.yaml) file for more details on this.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for more details.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Acknowledgments

* [SFML](https://www.sfml-dev.org/), the library used for creating this game.
