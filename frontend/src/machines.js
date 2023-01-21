import { createMachine } from "xstate";

export const drink_builder_machine = createMachine({
  // Machine identifier
  id: "light",

  // Initial state
  initial: "green",

  // Local context for entire machine
  context: {
    elapsed: 0,
    direction: "east",
  },

  // State definitions
  states: {
    green: {
      /* ... */
    },
    yellow: {
      /* ... */
    },
    red: {
      /* ... */
    },
  },
});

export const drink_list_machine = createMachine({
  // Machine identifier
  id: "light",

  // Initial state
  initial: "green",

  // Local context for entire machine
  context: {
    elapsed: 0,
    direction: "east",
  },

  // State definitions
  states: {
    green: {
      /* ... */
    },
    yellow: {
      /* ... */
    },
    red: {
      /* ... */
    },
  },
});
