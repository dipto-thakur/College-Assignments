import 'package:flutter/material.dart';

void main() => runApp(TemperatureConverterApp());

class TemperatureConverterApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Temperature Converter',
      home: TemperatureConverter(),
    );
  }
}

class TemperatureConverter extends StatefulWidget {
  @override
  _TemperatureConverterState createState() => _TemperatureConverterState();
}

class _TemperatureConverterState extends State<TemperatureConverter> {
  final TextEditingController _controller = TextEditingController();

  String _selectedFrom = 'Celsius';
  String _selectedTo = 'Fahrenheit';
  String _result = '';

  void _convertTemperature() {
    double inputTemp = double.tryParse(_controller.text) ?? 0;
    double convertedTemp;

    // Every combination first converts (conceptually) to Celsius as the
    // common ground, then out to the target unit. Written out as plain
    // if/else pairs here rather than a lookup table, since there are
    // only 3 units (9 combinations, 3 of which are same-to-same).
    if (_selectedFrom == 'Celsius' && _selectedTo == 'Fahrenheit') {
      convertedTemp = inputTemp * 9 / 5 + 32;
    } else if (_selectedFrom == 'Celsius' && _selectedTo == 'Kelvin') {
      convertedTemp = inputTemp + 273.15;
    } else if (_selectedFrom == 'Fahrenheit' && _selectedTo == 'Celsius') {
      convertedTemp = (inputTemp - 32) * 5 / 9;
    } else if (_selectedFrom == 'Fahrenheit' && _selectedTo == 'Kelvin') {
      convertedTemp = (inputTemp - 32) * 5 / 9 + 273.15;
    } else if (_selectedFrom == 'Kelvin' && _selectedTo == 'Celsius') {
      convertedTemp = inputTemp - 273.15;
    } else if (_selectedFrom == 'Kelvin' && _selectedTo == 'Fahrenheit') {
      convertedTemp = (inputTemp - 273.15) * 9 / 5 + 32;
    } else {
      // same unit on both sides, or any combination not listed above
      convertedTemp = inputTemp;
    }

    setState(() {
      _result = '${convertedTemp.toStringAsFixed(2)} $_selectedTo';
    });
  }

  @override
  void dispose() {
    _controller.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Temperature Converter'),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            TextField(
              controller: _controller,
              keyboardType: TextInputType.number,
              decoration: InputDecoration(
                labelText: 'Enter temperature',
                border: OutlineInputBorder(),
              ),
            ),
            SizedBox(height: 16),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceAround,
              children: [
                DropdownButton<String>(
                  value: _selectedFrom,
                  items: ['Celsius', 'Fahrenheit', 'Kelvin']
                      .map((unit) =>
                          DropdownMenuItem(value: unit, child: Text(unit)))
                      .toList(),
                  onChanged: (value) {
                    setState(() {
                      _selectedFrom = value!;
                    });
                  },
                ),
                Text('to'),
                DropdownButton<String>(
                  value: _selectedTo,
                  items: ['Celsius', 'Fahrenheit', 'Kelvin']
                      .map((unit) =>
                          DropdownMenuItem(value: unit, child: Text(unit)))
                      .toList(),
                  onChanged: (value) {
                    setState(() {
                      _selectedTo = value!;
                    });
                  },
                ),
              ],
            ),
            SizedBox(height: 20),
            ElevatedButton(
              onPressed: _convertTemperature,
              child: Text('Convert'),
            ),
            SizedBox(height: 20),
            Text(
              'Result: $_result',
              style: TextStyle(fontSize: 20),
            ),
          ],
        ),
      ),
    );
  }
}