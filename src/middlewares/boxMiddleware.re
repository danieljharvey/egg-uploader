/* this reducer only cares about looking for a complete box and adding it to the list */
/* Oh my sweet lord need to roll some sort of version of sequence to deal with validating multiple option types in a less shitty way*/
let getBox = (startCoord, endCoord) =>
  switch (startCoord) {
  | Some(startC) =>
    switch (endCoord) {
    | Some(endC) => Some((startC, endC))
    | _ => None
    }
  | _ => None
  };

let addToList = (startCoord, endCoord, boxes) =>
  switch (getBox(startCoord, endCoord)) {
  | Some(box) => Belt_List.add(boxes, box)
  | None => boxes
  };

/* this takes care of adding the current coords to a list if it works */
let boxMiddleware = (reducer: Types.reducer(Types.action, Types.state)) => {
  let (action: Types.action, state: Types.state) = reducer;
  switch (action) {
  | MouseUp(_, _) => {
      ...state,
      boxes: addToList(state.startCoord, state.endCoord, state.boxes),
    }
  | _ => state
  };
};