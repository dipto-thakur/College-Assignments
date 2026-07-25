# Sem 03 — Flutter & Dart App Development

Sixteen small Flutter apps, moving from basic input/calculation screens
through lists, timers, navigation, form validation, and animation. Each
one is meant to be its own standalone Flutter project.

## Assignments

| # | App | Core concept |
|---|---|---|
| 01 | Temperature Converter | Text input, dropdowns, unit conversion logic |
| 02 | BMI Calculator | Numeric input, conditional classification (Underweight/Normal/Overweight/Obese) |
| 03 | Age Calculator | Date parsing, date arithmetic |
| 04 | Stopwatch | Timers, real-time UI updates, start/stop/reset state |
| 05 | Voter Eligibility List | Lists, `map`/`toList`, filtering into two lists |
| 06 | Countdown Timer | Timers counting down, start/stop/reset state |
| 07 | Currency Converter | Dropdowns, predefined exchange rate table, conversion logic |
| 08 | Tip Calculator | Numeric input, percentage selection, INR formatting |
| 09 | Circle Area/Circumference | Dropdown-selected calculation mode |
| 10 | Flashcards App | Add/store question-answer pairs, review mode |
| 11 | Barbecue Station | AppBar, Drawer, FloatingActionButton, navigation to a new page |
| 12 | Random Names Viewer | Hardcoded list, button-triggered display, page navigation |
| 13 | Dynamic AppBar Title | StatefulWidget, text input driving AppBar state |
| 14 | Login Form Validation | Multi-rule form validation (username, email, password) |
| 15 | Animated Container | `AnimationController`, animating size and color over 1 second |
| 16 | Cross-Fade Image Switcher | `AnimatedCrossFade` between two images |

## Project Structure

Each assignment is meant to live in its own folder as an independent
Flutter project, generated with `flutter create`:

```
sem-03-flutter-dart-app-dev/
├── README.md
├── 01-temperature-converter/
│   └── lib/main.dart
├── 02-bmi-calculator/
│   └── lib/main.dart
├── 03-age-calculator/
│   └── lib/main.dart
├── ...
└── 16-cross-fade-image-switcher/
    └── lib/main.dart
```

Each subfolder README (once added) documents that specific assignment's
problem statement, widget tree approach, and how to run it. This
top-level file is the index.

## Environment Setup

These apps target Android Studio with the Flutter and Dart plugins
installed, running on an Android emulator or physical device.

1. Install [Flutter SDK](https://flutter.dev) and add it to your PATH.
2. Install Android Studio, then add the **Flutter** and **Dart**
   plugins from Preferences → Plugins.
3. Verify your setup:
   ```
   flutter doctor
   ```
4. Open any assignment folder in Android Studio as a Flutter project,
   or from the command line:
   ```
   cd 01-temperature-converter
   flutter pub get
   flutter run
   ```

## Common Concepts Across Assignments

A few Flutter/Dart building blocks come up repeatedly across this set,
worth knowing once rather than re-learning per assignment:

- **StatefulWidget + setState()** — nearly every app needs to redraw
  itself after user input (a converted value, a calculated BMI, a
  ticking timer), which is what assignments 1-9, 13, and 15-16 all lean
  on.
- **Timers (`Timer.periodic`)** — used in the stopwatch (04) and
  countdown timer (06), the two "live updating" apps in the set.
- **Form input & validation** — text fields and dropdowns are the
  primary input pattern (1, 2, 3, 7, 8, 9), culminating in assignment
  14's full multi-rule validation logic.
- **Navigation (`Navigator.push`)** — moving between pages/screens shows
  up in 11 (FAB → picture page) and 12 (button → second page).
- **Lists and collection methods** — `map()` and `toList()` specifically
  called out in assignment 5, filtering a list of people into two
  eligibility groups.
- **Animation** — `AnimationController` / implicit animations in 15, and
  `AnimatedCrossFade` in 16, the two purely visual/animation-focused
  assignments in the set.

## Notes

- All 16 problem statements specify Android Studio as the target IDE,
  but every app here is plain Flutter/Dart, so they'll run the same way
  via VS Code, IntelliJ, or the command line if that's your preference.
- Assignment 8 specifically calls for INR (₹) formatting, worth flagging
  since it's the one assignment with a currency-specific requirement
  baked into the problem statement rather than a general one.
- Assignment 14's password rule set (uppercase, lowercase, digit,
  special character, more than 6 characters) is stricter than its
  username rule (just a length check), worth keeping in mind since it's
  easy to under-implement the password side and only check length there
  too.