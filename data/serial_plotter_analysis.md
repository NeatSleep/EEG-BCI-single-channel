# Serial Plotter Output — Analysis

## Recording details
- Date: [02.04.2026]
- Subject: Self (pilot protocol)
- Electrode placement: A1/A2 (earlobes, active), Fpz (reference)
- Circuit: AD620AN + TL074, passive bandpass 0.5–50 Hz, Twin-T 50 Hz notch
- ADC: ESP32 GPIO 34, 12-bit, ~100 Hz sampling, 115200 baud

## What the output shows

Frames 1–14: Flat line at ADC value = 0  
Frames 15–24: Sporadic positive spikes, peak ~140 ADC counts (~0.11 V)  
Frames 25–38: Return to flat line at 0  

## Root cause diagnosis

The TL074 op-amp outputs a bipolar signal (swinging both above and below 0 V).
The ESP32 ADC input range is 0–3.3 V (unipolar).

Without a DC bias offset, any negative excursion of the TL074 output is
clipped to 0 by the ESP32. Only positive half-cycles are captured.
This produces the flat-zero baseline with occasional positive spikes.

The spikes in frames 15–24 are motion artifacts from electrode
contact events during setup — brief, high-amplitude positive transients.
They are not neural oscillations, which would appear as a sinusoidal
waveform, not isolated spikes from a zero baseline.

## Solution implemented

A two-resistor bias network was added between the TL074 output and the
ESP32 ADC input:
- 10 kΩ from circuit output to ADC pin
- 10 kΩ from ADC pin to ESP32 3.3 V rail
- Result: ~1.65 V DC midpoint at ADC input
- Effect: bipolar AC signal rides on 1.65 V baseline, full waveform within 0–3.3 V range

See esp32_biased.ino for the updated firmware.
Phase 2 validation of this correction is in progress.
