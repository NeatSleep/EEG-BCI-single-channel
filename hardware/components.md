# Hardware Components

| Component       | Value / Part No.     | Quantity | Purpose                        |
|-----------------|----------------------|----------|--------------------------------|
| AD620AN         | Instrumentation Amp  | 1        | Pre-amplifier stage            |
| TL074           | Quad Op-Amp          | 1        | Post-amplifier + active filter |
| Resistor        | 1 kΩ                 | 2        | Gain / filter network          |
| Resistor        | 4 kΩ                 | 2        | Filter network                 |
| Resistor        | 500 kΩ               | 2        | Gain setting (Rg)              |
| Resistor        | 10 kΩ                | 2        | Bias voltage divider           |
| Capacitor       | 1 µF                 | 5        | Bandpass + notch filter        |
| ESP32           | 30-pin DevKit        | 1        | 12-bit ADC, USB serial output  |
| AgCl Electrodes | Single-use ECG type  | 3        | Scalp signal acquisition       |
| Breadboard      | 830-point            | 1        | Prototyping                    |

## Circuit Parameters

- Pre-amp gain: G = (49.4 kΩ / Rg) + 1
- Post-amp gain: Gb = 1 + (Rf / R1)
- Bandpass: 0.5 – 50 Hz (2nd-order passive RC)
- Notch: 50 Hz Twin-T filter (powerline rejection)
- Target total gain: ~10,000×
- ADC: ESP32 GPIO 34, 12-bit (0–4095), ~100 Hz sampling
- Bias offset: 2 × 10 kΩ divider from 3.3 V rail → ~1.65 V midpoint
