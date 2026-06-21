# Abstract — Draft

**Paper title:**
EEG-Based Brain–Computer Interfaces: A Hardware-Grounded Survey of Six Paradigms

---

## Abstract (~250 words)

Brain–computer interface (BCI) research has advanced considerably in the past
two decades, with non-invasive electroencephalography (EEG) remaining the
dominant acquisition modality due to its low cost and portability. However,
the majority of published surveys evaluate BCI paradigms exclusively on
information transfer rate (ITR) and classification accuracy measured on
high-quality, multichannel laboratory data — leaving hardware feasibility
as an unexamined axis. This gap is consequential: a paradigm that achieves
90% accuracy on a 64-channel amplifier may be entirely undeployable on the
low-cost, single-channel hardware that defines real-world accessibility.

This paper presents a hardware-grounded survey of six major EEG-BCI paradigms:
motor imagery (event-related desynchronisation and synchronisation), P300
evoked potentials, steady-state visual evoked potentials (SSVEP),
error-related negativity (ERN), imagined speech decoding, and hybrid/passive
BCI systems. For each paradigm, we apply a six-axis hardware constraint
taxonomy — evaluating minimum bandwidth requirement, minimum channel count,
electrode placement specificity, signal-to-noise ratio tolerance, calibration
burden, and stimulus dependency — derived from first-principles signal chain
analysis and validated across three stages: (1) Proteus 9 circuit simulation
confirming gain, bandpass, and notch filter behaviour across the full signal
chain; (2) physical breadboard prototype construction (AD620AN instrumentation
amplifier, TL074 post-amplifier, 0.5–50 Hz passband, 50 Hz Twin-T notch
filter, ESP32 12-bit ADC), bench-verified against signal generator inputs
(DSO measurement: 140 mV differential → 608 mV output); and (3) Phase 1
human self-experimentation using AgCl electrodes placed per the 10-20
International EEG System (A1/A2 active, Fpz reference), with oscillatory
activity consistent with alpha-band rhythm (8–13 Hz) observed on DSO
during eyes-closed relaxation state.

Our analysis reveals a clear stratification: P300 (1–12 Hz, single posterior
electrode, zero calibration) and SSVEP (single occipital electrode,
subject-independent) are deployable on minimal hardware; motor imagery
requires at minimum bilateral motor coverage; imagined speech decoding is
fundamentally constrained at EEG spatial resolution and bandwidth, regardless
of classification algorithm. We argue that hardware feasibility should be
treated as a first-class evaluation criterion in BCI benchmarking, and propose
the six-axis taxonomy as a reproducible framework for future paradigm comparison.

**Keywords:** brain–computer interface, EEG, motor imagery, P300, SSVEP,
error-related negativity, imagined speech, hardware constraints,
low-cost BCI, signal acquisition

---

## Status

- [ ] Section 1 — Introduction (draft complete)
- [ ] Section 2 — Signal chain and hardware taxonomy (in progress)
- [ ] Section 3 — Motor imagery (in progress)
- [ ] Section 4 — P300 (in progress)
- [ ] Section 5 — SSVEP (to write)
- [ ] Section 6 — ERN (to write)
- [ ] Section 7 — Imagined speech (to write)
- [ ] Section 8 — Hybrid and passive BCIs (to write)
- [ ] Section 9 — Cross-paradigm analysis table (to write)
- [ ] Section 10 — Single-channel feasibility analysis (to write)
- [ ] Section 11 — Open problems (to write)
- [ ] Section 12 — Conclusion (to write)

Target venue: IEEE Transactions on Neural Systems and Rehabilitation Engineering
Backup venue: Frontiers in Human Neuroscience
arXiv preprint: eess.SP or cs.HC (post before journal submission)
