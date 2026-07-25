# Assignment 01 — Temperature Converter

## Problem

Develop a Flutter app using Dart that converts temperatures between
Celsius, Fahrenheit, and Kelvin. The app should include an input field
for the temperature value, dropdown menus to select the input and
output units, and a button to perform the conversion. Display the
converted result within the app's interface.

## How it works

The whole app is one `StatefulWidget`, `TemperatureConverter`, since the
UI needs to redraw itself whenever the user changes a dropdown or hits
convert.

- **`TextEditingController`** reads whatever the user types into the
  input field. `double.tryParse(...)  ?? 0` is used instead of a plain
  `double.parse(...)`, so an empty or invalid input falls back to `0`
  rather than crashing the app.
- **Two `DropdownButton<String>` widgets** hold the "from" and "to"
  units, each backed by its own state variable (`_selectedFrom`,
  `_selectedTo`) that gets updated inside `setState()` whenever the user
  picks a different option.
- **`_convertTemperature()`** is a straightforward if/else ladder
  covering all six real conversion directions (C→F, C→K, F→C, F→K, K→C,
  K→F), with a fallback branch for when the two units are the same
  (nothing to convert). The formulas themselves are the standard ones:
  `F = C × 9/5 + 32`, `K = C + 273.15`, and their inverses.
- The result gets built as a string with `toStringAsFixed(2)` (so it
  reads like `98.60 Fahrenheit` instead of a long floating-point tail)
  and stored in `_result`, which is what the `Text('Result: $_result')`
  widget at the bottom displays.

## What was fixed from the pasted code

The version this was built from had clearly gone through a copy-paste
step that mangled double letters, `Flutter` had become `Flu er`,
`Button` had become `Bu on`, `TextEditingController` had become
`TextEdi ngController`, `title` had become `tle`, and `decoration` /
`InputDecoration` had become `decora on` / `InputDecora on`, that kind
of corruption. All of those are restored to their correct spellings
here, since Dart won't compile misspelled class or property names.

Two small real additions on top of that cleanup:
- `State<TemperatureConverter>` — the original was missing its generic
  type argument (just `State { ... }`), which won't compile as written,
  a `State` class always needs to say which widget it belongs to.
- Added a `dispose()` override that disposes the `TextEditingController`
  when the widget is removed, standard practice for any controller to
  avoid leaking resources, and added an `OutlineInputBorder()` to the
  text field purely for a slightly more finished look, functionality is
  otherwise identical to the original.

## Run it

```
flutter pub get
flutter run
```

## Sample interaction

1. Enter `100` in the input field.
2. Leave "from" as `Celsius`, set "to" to `Fahrenheit`.
3. Tap **Convert**.
4. Result reads: `Result: 212.00 Fahrenheit`