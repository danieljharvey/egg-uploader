/* this reducer only cares about looking for a complete box and adding it to the list */
/* Oh my sweet lord need to roll some sort of version of sequence to deal with validating multiple option types in a less shitty way*/
let getBoxLocation = (startCoord, endCoord) =>
  switch (startCoord) {
  | Some(startC) =>
    switch (endCoord) {
    | Some(endC) => Some((startC, endC))
    | _ => None
    }
  | _ => None
  };

let addToList =
    (
      startCoord: option(CanvasTypes.coord),
      endCoord: option(CanvasTypes.coord),
      boxes: list(CanvasTypes.box),
    ) =>
  switch (getBoxLocation(startCoord, endCoord)) {
  | Some(location) => Belt_List.add(boxes, {title: "New box", location})
  | None => boxes
  };

/* this takes care of adding the current coords to a list if it works */
let boxMiddleware =
    (reducer: PipeTypes.reducer(CanvasTypes.action, CanvasTypes.state)) => {
  let (action: CanvasTypes.action, state: CanvasTypes.state) = reducer;
  switch (action) {
  | MouseUp(_, _) => {
      ...state,
      boxes: addToList(state.startCoord, state.endCoord, state.boxes),
    }
  | _ => state
  };
};