# Qt Level Manager

This directory contains a small Qt-based console application that loads the Mario text levels shipped with the project. It exposes a `LevelManager` class that discovers level files, validates them through `LevelLoader`, and exposes metadata such as start/finish positions.

## Building

```bash
cmake -S qt -B qt/build
cmake --build qt/build
```

The build expects Qt 6 with the `Core` module available on your system. After building, run the executable from the repository root so the default level path resolves correctly:

```bash
./qt/build/level_manager ../Mario-AI-Framework/levels/original lvl-1.txt
```

You can pass an alternate level directory or filename via command-line arguments.
