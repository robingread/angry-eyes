# Change Log

Please refer to keepachnagelog.org when editing this file.

## [Unreleased]

### Changed
- Added padding for the eyebrows around the pupile so that we get cleaner rendering.
- Eyebrow thickness can extend to the full diameter of the eyes rather than just the radius. This will allow for far more flexibility when it comes to expressive blinking, for example.
- Updated FaceConfig to store an inter-ocular distance and updated the GUI write to this model parmeter as well as render using it.

## [0.0.1] - 2021/12/10

### Added
- `README.md` and `CHANGELOG.md`
- Initial implementation of code in `include/` and `src/` directories.
- Basic example of running the app in a Docker container.
- Setup CI pipeline for Gitlab to allow a compile test.
