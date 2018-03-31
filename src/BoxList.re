let component = ReasonReact.statelessComponent("BoxListComponent");

let renderCoords = (coords: CanvasTypes.coord) : string =>
  string_of_int(coords.x) ++ ", " ++ string_of_int(coords.y);

let renderItem = (index: int, box: CanvasTypes.box) => {
  let (startCoord, endCoord) = box.location;
  <div>
    <h3> (ReasonReact.stringToElement(box.title)) </h3>
    <p key=(string_of_int(index))>
      (
        ReasonReact.stringToElement(
          renderCoords(startCoord) ++ " to " ++ renderCoords(endCoord),
        )
      )
    </p>
  </div>;
};

let makeElementArray = (boxes: list(CanvasTypes.box)) =>
  Array.of_list(List.mapi(renderItem, boxes));

let make = (~boxes: list(CanvasTypes.box), _children) => {
  ...component,
  render: self_ =>
    <div> (ReasonReact.arrayToElement(makeElementArray(boxes))) </div>,
};