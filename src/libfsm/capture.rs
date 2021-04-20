use std::collections::hash_map::{HashMap, Entry};

use crate::state::State;

// Keep in sync with capture.h capture_action_type
#[repr(C)]
enum ActionType {
    /// Start an active capture if transitioning to TO.
    Start,

    /// Continue an active capture if transitioning to TO, otherwise deactivate it.
    Extend,

    /// Write a zero-step capture (i.e., the start and end state are the same).
    CommitZeroStep,

    /// Write an active capture's endpoints.
    Commit
}

struct Action {
    ty: ActionType,
    id: u32,

    // only used by ActionType Start and Extend
    to: Option<State>,
}

struct CaptureInfo {
    max_capture_id: u32,
    actions: HashMap<State, Action>,
}

impl CaptureInfo {
    fn new() -> Self {
        Self {
            max_capture_id: 0,
            actions: HashMap::new(),
        }
    }

    fn count(&self) -> u32 {
        if self.actions.len() == 0 {
            0
        } else {
            self.expensive_check_max_capture_id();

            self.max_capture_id + 1
        }
    }

    // Originally this was gated behind an `#if EXPENSIVE_CHECKS`, always set to 1.
    // We may want to enable it conditionally or only under `#[cfg(test)]`
    fn expensive_check_max_capture_id(&self) {
        for (state, action) in self.actions.iter() {
            assert!(self.max_capture_id >= action.id);
        }
    }

    fn add_action(&mut self, state: State, action: Action) {
        // FIXME: capture.c:add_capture_action() has the following assertions:
	// assert(state < fsm->statecount);
	// assert(action->to == CAPTURE_NO_STATE || action->to < fsm->statecount);
        //
        // Here we don't know the fsm, so we should remember to do those assertions
        // in the fsm code once it is ported.

        if action.id > self.max_capture_id {
            self.max_capture_id = action.id;
        }

        // FIXME: capture.c:add_capture_action() uses simple linear probing,
        // but collisions are determined by the action value, not by the state key.
        // I don't know yet if duplicate keys (duplicate states) are possible.
        // For now, here we just replace any existing actions keyed by their state.
        self.actions.insert(state, action);
    }

    
}
