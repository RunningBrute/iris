# Iris

## Overview

Iris is a modern C++20 engine designed for asynchronous ingestion and processing of endurance training data stored in Garmin FIT files.

The project focuses on building a clean, explicit concurrency model using C++20 coroutines, asynchronous I/O, and a structured data processing pipeline.

The initial scope of the project is offline processing of locally stored FIT files, with the possibility to support future integration with remote data sources such as Garmin Connect.

### Name Origin

The name *iris* is inspired by the Greek goddess Iris, the messenger of the gods.

In mythology, Iris served as a link between different realms, symbolizing communication, transition, and information flow. This aligns closely with the core idea of the project: moving data through clearly defined stages of ingestion, transformation, and analysis without blocking execution.

## Scope

## Architecture (High Level)

## Coroutine Model

## Async I/O

## FIT Processing

Iris uses the official Garmin FIT SDK (C++ implementation) for decoding and interpreting FIT activity files.

The SDK is included directly in the repository as a vendored dependency under `vendor/garmin/fit`. This approach was chosen to ensure full control over the build process, avoid external runtime dependencies, and allow development on environments with limited tooling (e.g. Termux).

## Repository Structure

The repository is organized to clearly separate core application logic, third-party dependencies, and build artifacts.

The `vendor/` directory contains third-party code that is built as part of the project. Vendoring is used intentionally to ensure deterministic builds and full control over dependencies.

Build artifacts (e.g. `build/`) and test data files are excluded from version control.

## Build

Iris uses CMake and requires a C++20 compiler f.e. MSVC

### Requirements
- cmake
- ninja
- MSVC

### Build (Windows, Ninja)

From the repository root:

```bash
cmake -S . -B build -G Ninja
cmake --build build
```

The resulting executable will be available in the build/ directory.
