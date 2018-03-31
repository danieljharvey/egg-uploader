let component = ReasonReact.statelessComponent("BoxListComponent");

let renderCoords = (coords: Types.coord) : string =>
  string_of_int(coords.x) ++ ", " ++ string_of_int(coords.y);

let renderItem = (box: Types.box) => {
  let (startCoord, endCoord) = box;
  <p>
    (
      ReasonReact.stringToElement(
        renderCoords(startCoord) ++ " to " ++ renderCoords(endCoord),
      )
    )
  </p>;
};

let makeElementArray = (boxes: list(Types.box)) =>
  Array.of_list(List.map(renderItem, boxes));

let make = (~boxes: list(Types.box), _children) => {
  ...component,
  render: self_ =>
    <div> (ReasonReact.arrayToElement(makeElementArray(boxes))) </div>,
};